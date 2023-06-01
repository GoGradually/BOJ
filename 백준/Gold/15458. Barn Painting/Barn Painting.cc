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

vector<int> g[100001];
ll dp[100001][4];
int coloured[100001];

void dfs(int now, int past) {
    if (coloured[now] == 0) {
        dp[now][1] = 1;
        dp[now][2] = 1;
        dp[now][3] = 1;
    } else {
        dp[now][coloured[now]] = 1;
    }
    for (int i = 0; i < g[now].size(); i++) {
        int next = g[now][i];
        if (next == past) continue;
        dfs(next, now);
        if (coloured[now] != 0) {
            ll val = 0;
            for (int j = 1; j <= 3; j++) {
                if (j != coloured[now]) {
                    val += dp[next][j];
                    val %= MOD;
                }
            }
            dp[now][coloured[now]] *= val;
            dp[now][coloured[now]] %= MOD;
        } else {
            for (int j = 1; j <= 3; j++) {
                ll val = 0;
                for (int k = 1; k <= 3; k++) {
                    if (j == k) continue;
                    val += dp[next][k];
                    val %= MOD;
                }
                dp[now][j] *= val;
                dp[now][j] %= MOD;
            }
        }
    }
}

void Solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        coloured[a] = b;
    }
    dfs(1, 0);
    ll ans = 0;
    for (int i = 1; i <= 3; i++) {
        ans += dp[1][i];
        ans %= MOD;
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
