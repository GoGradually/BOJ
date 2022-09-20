#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;

void solve() {
    ll dp[10001];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    int n;
    cin >> n;
    for (int i = 2; i <= n; i += 2) {
        for (int j = 0; j <= i - 2; j += 2) {
            dp[i] += dp[j] * dp[i - 2 - j];
            dp[i] %=987654321;
        }
    }
    cout << dp[n] << '\n';
}

int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while (t--) solve();
    return 0;
}
