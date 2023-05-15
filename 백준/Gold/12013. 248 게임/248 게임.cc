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

int dp[249][249];
int arr[249];
void Solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> dp[i][i];
    }
    int mx = 0;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i + k < n; i++) {
            for (int j = i; j < i + k; j++) {
                if (dp[i][j] != 0 && dp[i][j] == dp[j + 1][i + k]) {
                    dp[i][i + k] = max(dp[i][i + k], dp[i][j] + 1);
                }
            }
            mx = max(mx, dp[i][i + k]);
        }
    }
    cout << mx << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--) Solve();
    return 0;
}
