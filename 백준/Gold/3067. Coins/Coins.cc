#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;

vector<pair<ll, int>> g[100001];

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int m;
    cin >> m;
    int dp[10001];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        dp[0] = 1;
    }
    for (int k = 0; k < n; k++) {                    // coin[0]부터 시작
        for (int i = 1; i <= m; i++) {               // 1원부터 시작
            if(i<arr[k])continue;
            dp[i] += dp[i - arr[k]];
        }
    }
    cout << dp[m] << '\n';
}

int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
