#include <algorithm>
#include <array>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define MOD 1000000007
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10

using namespace std;

int n, limit;
int arr[10001];

bool check(int x) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int time = 0;
    for (int i = 0; i < n; i++) {
        if (pq.size() == x) {
            time = pq.top();
            pq.pop();
        }
        pq.push(time + arr[i]);
    }
    int ans = 0;
    while (!pq.empty()) {
        ans = max(pq.top(), ans);
        pq.pop();
    }
    if (ans <= limit)
        return true;
    else
        return false;
}
int first_true(int lo, int hi) {
    hi++;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

void solve() {
    cin >> n >> limit;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ans = first_true(0, 1000000);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
