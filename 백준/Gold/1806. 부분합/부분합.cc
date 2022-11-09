#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define MOD 998244353LL
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;
void solve() {
    int n, s;
    cin>>n>>s;
    vector<int> arr(n);
    vector<ll> psum(n+1, 0);
    for(int i = 0; i<n; i++) cin>>arr[i];
    for(int i = 0; i<n; i++) psum[i+1] = psum[i] + arr[i];
    int left = 0, right = 1;
    ll ans = 100001;
    while(left < right && right <= n){
        ll sum = psum[right] - psum[left];
        if(sum>=s){
            ans = ans > (right-left) ? (right-left) : ans;
            left++;
            if(left>=right) right++;
        }
        else right++;
    }
    if(ans == 100001) cout<<0<<'\n';
    else
    cout<<ans<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
