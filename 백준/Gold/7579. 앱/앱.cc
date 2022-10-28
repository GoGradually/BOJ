#include <bits/stdc++.h>
#define MOD 1000000007LL
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;

ll dp[101][10001];
bool ok[101][10001];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n), cost(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    memset(dp, 0, sizeof(dp));
    memset(ok, false, sizeof(ok));
    ok[0][0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 10000; j++) {
            if (ok[i][j]) {
                ok[i + 1][j] = true;
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                ok[i + 1][j + cost[i]] = true;
                dp[i + 1][j + cost[i]] =
                    max(dp[i][j] + arr[i], dp[i + 1][j + cost[i]]);
            }
        }
    }
    for (int i = 0; i < 10001; i++) {
        if (dp[n][i] >= m) {
            cout << i << '\n';
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
