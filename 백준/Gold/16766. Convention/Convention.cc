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

int n, limit, c;
int arr[100001];

bool check(int x) {
    int start = 0;
    int val = 0;
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] - arr[start] > x || cnt == c) {
            val++;
            start = i;
            cnt = 0;
        }
        cnt++;
    }
    if (cnt != 0) val++;
    if (val > limit)
        return false;
    else
        return true;
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
    cin >> n >> limit >> c;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int ans = first_true(0, 1000000000);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
