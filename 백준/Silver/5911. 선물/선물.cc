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

bool cmp(pair<int, int> &a, pair<int, int> &b){
    if(a.first+a.second==b.first+b.second){
        return a.first> b.first;
    }
    return a.first+a.second<b.first+b.second;
}
int go(int remain,int choose, bool chance, int index, vector<pair<int,int>> &arr){
    if(remain<0){
        return choose-1;
    }
    if(arr.size()==index) return choose;
    int val = go(remain - arr[index].first-arr[index].second, choose+1, chance, index+1, arr);
    if(chance){
        val = max(val, go(remain-arr[index].first/2-arr[index].second, choose+1, false, index+1, arr));
    }
    return val;
}
void solve() {
    int n, gold;
    cin>>n>>gold;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i<n; i++) {
        int a, b;
        cin>>a>>b;
        arr[i] = {a, b};
    }
    sort(arr.begin(), arr.end(), cmp);
    cout<<go(gold, 0, true, 0, arr)<<'\n';
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
