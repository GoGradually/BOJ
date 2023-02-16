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
vector<int> chord(89,0);
void solve() {
    int n, c;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    cin>>c;
    vector<int> ch(c);
    for (int i =0; i<c; i++) {
        cin>>ch[i];
    }
    sort(ch.begin(),ch.end());
    for (int i = 0; i<c; i++) {
        chord[ch[i]-ch[0]]++;
    }
    vector<int> ans;
    for (int i = 0; i+c<=n; i++) {
        int minVal = 89;
        for (int j = i; j<i+c; j++) {
            minVal = min(minVal, arr[j]);
        }
        vector<int> temp(89, 0);
        for (int j = i; j<i+c; j++) {
            temp[arr[j]-minVal]++;
        }
        bool sick = true;
        for (int j = 0; j<89; j++) {
            if(temp[j] != chord[j]) sick=false;
        }
        if(sick) ans.push_back(i+1);
    }
    cout<<ans.size()<<'\n';
    for (int i = 0; i<ans.size(); i++) {
        cout<<ans[i]<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
