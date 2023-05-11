#include <bits/stdc++.h>
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
#define MOD 1000000007LL;
/*
#include "atcoder/modint.hpp"
using mint = atcoder::modint998244353;
*/

using namespace std;

vector<pair<int, int>> g;
int arr[1001];
int dp[1001][1001];
void Solve() {
    int n, m, c;
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g.push_back({b, a});
    }
    memset(dp, -1, sizeof(dp));
    dp[1][1] = 0;
    for (int day = 2; day <= 1001; day++) {
        for (int i = 0; i<m; i++) {
            if(dp[g[i].second][day-1] != -1){
                dp[g[i].first][day] = max(dp[g[i].first][day], dp[g[i].second][day-1] + arr[g[i].first]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i < 1001; i++) {
        ans = max(ans, dp[1][i] - c * (i - 1) * (i - 1));
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--) Solve();
    return 0;
}
