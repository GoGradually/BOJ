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

int dp[400][400][2];
int dp2[400][400];
void solve() {
    int n,m;
    cin>>n>>m;
    vector<string> arr(n);
    for (int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    for (int i = n-1; i>=0; i--) {
        for (int j = m-1; j>=0; j--) {
            if(arr[i][j] == 'X'){
                dp[i][j][0] = 0;
                dp[i][j][1] = 0;
            }else{
                if(j==m-1)  dp[i][j][0] = 1;
                else dp[i][j][0] = dp[i][j+1][0] + 1;
                if(i==n-1) dp[i][j][1] = 1;
                else dp[i][j][1] = dp[i+1][j][1] + 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            int MIN = 2000;
            for (int k = 0; k<dp[i][j][0]; k++) {
                if(MIN>dp[i][j+k][1])MIN = dp[i][j+k][1];
                dp2[i][j] = max(dp2[i][j], MIN*2 + (k+1)*2);
            }
            ans = max(ans, dp2[i][j]);
        }
    }
    cout<<ans-1<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
