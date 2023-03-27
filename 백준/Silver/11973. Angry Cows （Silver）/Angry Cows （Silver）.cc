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
int arr[100001];

bool check(int x) {
    int val = 0;
    int cnt = 1;
    int start = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] - start > 2 * x) {
            start = arr[i];
            cnt = 0;
            val++;
        }
        cnt++;
    }
    val++;
    if (val <= limit)
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
