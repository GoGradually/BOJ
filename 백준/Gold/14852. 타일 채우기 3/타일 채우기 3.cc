#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int n;
long long dp[1000001];
long long sum[1000001];
void solve(){
    memset(dp, 0,sizeof(dp));
    cin>>n;
    dp[0] = 1;
    dp[1] = 2;
    sum[0] = 2;
    sum[1] = 6;
    for (int i = 2; i<=n; i++) {
        dp[i] = (dp[i-1]*2 + dp[i-2] * 3)%MOD;
        dp[i] = (dp[i] + sum[i-3])%MOD;
        sum[i] = (dp[i]*2 + sum[i-1])%MOD;
    }
    cout<<dp[n]<<'\n';
}

int main(int argc, const char * argv[]) {
    int t;
    t = 1;
    while(t--) solve();
    return 0;
}
