#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> arr(20);
int dp[1001];
int c, n;
int go(int num){
    if(num<=0) return 0;
    if(dp[num]>0) return dp[num];
    int ret = 1000*1000;
    int cost;
    for (int i = 0; i<n; i++) {
        cost = arr[i].first + go(num-arr[i].second);
        if(cost < ret) ret = cost;
    }
    return dp[num] = ret;
}
void solve(){
    cin>>c>>n;
    for (int i = 0; i<n; i++) {
        cin>>arr[i].first>>arr[i].second;
    }
    cout<<go(c)<<'\n';
}

int main(int argc, const char * argv[]) {
    int t;
    t = 1;
    while(t--) solve();
    return 0;
}
