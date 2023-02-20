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

int n;

char sum(char a, char b){
    return a+b-'0';
}
int go(vector<string> &arr, string str, int index, int val){
    if(index == n){
        for (int i = 0; i<str.size(); i++) {
            if(!(str[i] >= '0' && str[i]<= '9')) return -1;
        }
        return val;
    }
    int ans = go(arr, str, index+1, val);
    for (int i = arr[index].size()-1; i>=0; i--) {
        int j = str.size() - arr[index].size() + i;
        str[j] = sum(arr[index][i], str[j]);
    }
    ans = max(ans, go(arr, str, index+1, val+1));
    return ans;
}
void solve() {
    cin>>n;
    vector<string> arr(n);
    for (int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    string str = "00000000000";
    cout<<go(arr, str, 0, 0)<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
