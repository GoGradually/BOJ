#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    ll dp[10001];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j < arr[i]) continue;
            dp[j] += dp[j - arr[i]];
        }
    }
    cout << dp[k] << '\n';
}

int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while (t--) solve();
    return 0;
}
