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

void solve() {
    int n, k;
    cin>>n>>k;
    vector<pair<int, int>> order;
    for (int i = 0; i<k; i++) {
        int a, b;
        cin>>a>>b;
        order.push_back({a-1, 1});
        order.push_back({b, 0});
    }
    sort(order.begin(), order.end());
    stack<int> stk;
    int now = 0;
    int index = 0;
    vector<int> ans(n);
    while(now<n){
        while (index<order.size()&&order[index].first < now) {
            if(order[index].second==1){
                stk.push(1);
            }
            else{
                stk.pop();
            }
            index++;
        }
        ans[now] = stk.size();
        now++;
    }
    sort(ans.begin(), ans.end());
    cout<<ans[n/2]<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
