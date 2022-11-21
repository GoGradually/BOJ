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

map<int, int> ans[300][300];
void solve() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i<n; i++)cin>>arr[i];
    sort(arr.begin(), arr.end());
    int left = 0, right = n-1;
    vector<int> trans1, trans2;
    while(left<right){
        trans1.push_back(arr[left]);
        trans1.push_back(arr[right]);
        trans2.push_back(arr[right]);
        trans2.push_back(arr[left]);
        left++;
        right--;
        if(left==right){
            trans1.push_back(arr[left]);
            trans2.push_back(arr[left]);
            left++;
        }
    }
    ll ans = 0, ans2 = 0;
    for(int i = 1; i<n-1; i++){
        ans+=abs(trans1[i]-trans1[i-1]);
        ans2+=abs(trans2[i]-trans2[i-1]);
    }
    ans+=abs(trans1[n-1]-trans1[0]);
    ans2+=abs(trans2[n-1]-trans2[0]);

    cout<<max(ans,ans2)<<'\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
