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
    sum[0] = 1;
    sum[1] = 3;
    for (int i = 2; i<=n; i++) {
        dp[i] = (dp[i-1]*2 + dp[i-2] * 3)%MOD;
        dp[i] = (dp[i] + 2*sum[i-3])%MOD;
        sum[i] = (dp[i] + sum[i-1])%MOD;
    }
    cout<<dp[n]%MOD<<'\n';
}

int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while(t--) solve();
    return 0;
}
