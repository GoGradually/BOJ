#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define MOD 1000000000LL
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;

ll dp[501][501];
int n;

ll go(int x, int y, vector<int> &arr, vector<int> &psum) {
    if (dp[x][y] != -1) return dp[x][y];
    ll &ret = dp[x][y];
    if (x == y) return ret = 0;
    if (x + 1 == y) return ret = arr[x - 1] + arr[y - 1];
    ret = lINF;
    for (int i = x; i < y; i++) {
        ret = min(ret, go(x, i, arr, psum) + go(i + 1, y, arr, psum) + psum[y] -
                           psum[x - 1]);
    }
    return ret;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> n;
    vector<int> arr(n), psum(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        psum[i + 1] = psum[i] + arr[i];
    }
    cout << go(1, n, arr, psum) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
