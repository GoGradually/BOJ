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
#define MOD 998244353
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;

ll dp[501][501];
ll arr[501][501];
int n, m;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
ll go(int x, int y) {
    if (x == 0 && y == 0) return 1;
    if (dp[x][y] != -1) return dp[x][y];
    ll &ret = dp[x][y];
    ret = 0;
    for (int k = 0; k < 4; k++) {
        int p = x + dx[k], q = y + dy[k];
        if (p >= 0 && p < n && q >= 0 && q < m) {
            if (arr[x][y] < arr[p][q]) {
                ret += go(p, q);
            }
        }
    }
    return ret;
}
void solve() {
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    cout << go(n - 1, m - 1) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
