#include <algorithm>
#include <array>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define MOD 998244353
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;
int dp[10001][11];
void solve() {
    int n, m;
    cin>>n>>m;
    vector<int> arr(n);
    for (int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    for (int i = 0; i<=n; i++) {
        for (int j = 0; j<=m; j++) {
            dp[j][i] = INF;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i<n; i++) {
        for (int w = 0; w<=m; w++) {
            for (int c = 0; c<=100; c++) {
                if(w - c*c >= 0 && dp[w-c*c][i] != INF)
                    dp[w][i+1] = min(dp[w][i+1], dp[w - c*c][i] + (arr[i] - c) * (arr[i] - c));
            }
        }
    }
    if(dp[m][n] == INF) cout<<-1<<'\n';
    else
        cout<<dp[m][n]<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
