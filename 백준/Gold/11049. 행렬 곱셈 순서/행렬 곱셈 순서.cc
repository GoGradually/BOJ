#include <bits/stdc++.h>
#define MOD 998244353LL
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;

ll dp[501][501];
int arr[501][2];
int n;
ll go(int x, int y) {
    if (dp[x][y] != -1) return dp[x][y];
    if (y == x) return dp[x][y] = 0;
    if (y - x == 1) {
        return dp[x][y] = arr[x][0] * arr[y][0] * arr[y][1];
    }
    ll &ret = dp[x][y];
    ret = lINF;
    for (int i = x; i < y; i++) {
        ret = min(ret,
                  go(x, i) + go(i + 1, y) + arr[x][0] * arr[i][1] * arr[y][1]);
    }
    return ret;
}
void solve() {
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }
    cout << go(0, n - 1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
