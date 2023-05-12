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

deque<ll> arr;
ll dp[100][101][8];
void Solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    if (n <= k) {
        cout << 0 << '\n';
        return;
    }
    reverse(arr.begin(), arr.end());
    ll ans = lINF;
    memset(dp, -1, sizeof(dp));
    for (int t = 0; t < n; t++) {
        dp[t][0][0] = 0;
        for (int h = 1; h <= k; h++) {
            for (int i = 1; i <= n; i++) {
                dp[t][i][h] = lINF;
                ll val = 0;
                for (int j = i - 1; j >= 0; j--) {
                    val += (i - (j + 1)) * arr[j];
                    if (dp[t][j][h - 1] != -1) {
                        dp[t][i][h] = min(dp[t][i][h], dp[t][j][h - 1] + val);
                    }
                }
            }
        }

        ans = min(ans, dp[t][n][k]);
        ll temp = arr[0];
        arr.pop_front();
        arr.push_back(temp);
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
