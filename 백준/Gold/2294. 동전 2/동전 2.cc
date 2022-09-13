#include <bits/stdc++.h>
using namespace std;

vector<int> arr(100);
bool check[100];
int dp[100001];
int c, n;
int go(int num){
    if(num==0) return 0;
    if(dp[num] != -1) return dp[num];
    int ret = 1000*1000;
    int cnt;
    for (int i = 0; i<n; i++) {
        if(num >= arr[i]){
            cnt = go(num-arr[i]) + 1;
            if(ret > cnt) ret = cnt;
        }
    }
    return dp[num] = ret;
}
void solve(){
    cin>>n>>c;
    memset(check, false, sizeof(check));
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    int ans = go(c);
    if(ans == 1000000){
        cout<<-1<<'\n';
    }
    else{
        cout<<ans<<'\n';
    }
}

int main(int argc, const char * argv[]) {
    int t;
    t = 1;
    while(t--) solve();
    return 0;
}
