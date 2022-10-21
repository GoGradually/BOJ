#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
#define MOD 1000000007LL
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;

long long dp[51][51][51][51];
void solve() {
    int n, p, q, r;
    cin >> n >> p >> q >> r;
    memset(dp, 0, sizeof(dp));
    dp[0][0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int x = 0; x <= p; x++) {
            for (int y = 0; y <= q; y++) {
                for (int z = 0; z <= r; z++) {
                    if (x > 0) dp[i][x][y][z] += dp[i - 1][x - 1][y][z];
                    dp[i][x][y][z] %= MOD;
                    if (y > 0) dp[i][x][y][z] += dp[i - 1][x][y - 1][z];
                    dp[i][x][y][z] %= MOD;
                    if (z > 0) dp[i][x][y][z] += dp[i - 1][x][y][z - 1];
                    dp[i][x][y][z] %= MOD;
                    if (x > 0 && y > 0)
                        dp[i][x][y][z] += dp[i - 1][x - 1][y - 1][z];
                    dp[i][x][y][z] %= MOD;
                    if (y > 0 && z > 0)
                        dp[i][x][y][z] += dp[i - 1][x][y - 1][z - 1];
                    dp[i][x][y][z] %= MOD;
                    if (x > 0 && z > 0)
                        dp[i][x][y][z] += dp[i - 1][x - 1][y][z - 1];
                    dp[i][x][y][z] %= MOD;
                    if (x > 0 && y > 0 && z > 0)
                        dp[i][x][y][z] += dp[i - 1][x - 1][y - 1][z - 1];
                    dp[i][x][y][z] %= MOD;
                }
            }
        }
    }
    cout << dp[n][p][q][r] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
