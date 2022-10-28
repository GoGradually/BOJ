#include <bits/stdc++.h>
#define MOD 1000000007LL
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;

ll dp[101][10001];

void solve() {
    int n = 100, m = 100;
    cin>>n>>m;
    vector<int> arr(n);
    vector<int> cost(n);
    for(int i = 0; i<n; i++) cin>>arr[i];
    for(int i = 0; i<n; i++) cin>>cost[i];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= 10000; j++) {
            if (j + cost[i] <= 10000)
                dp[i + 1][j + cost[i]] =
                    max(dp[i][j] + arr[i], dp[i][j + cost[i]]);
            dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
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
