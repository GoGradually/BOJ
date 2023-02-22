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

bool cmp(int a, int b){
    if(abs(a)==abs(b)){
        return a<b;
    }
    return abs(a)<abs(b);
}

void solve() {
    int n, l;
    cin>>n>>l;
    l*=2;
    vector<int> arr(n);
    for (int i = 0; i<n; i++) {
        cin>>arr[i];
        arr[i]*=2;
    }
    int ans = 0;
    for (int fold = 1; fold<l; fold++) {
        vector<int> point(min(l - fold, fold)+1, 0);
        bool ok = true;
        for (int i = 0; i<n; i++) {
            if(abs(arr[i] - fold)>=point.size()){
                continue;;
            }
            point[abs(arr[i]-fold)]++;
        }
        for (int i = 1; i<point.size(); i++) {
            if(point[i]==1) ok = false;
        }
        if(ok) {
            ans++;
        }
    }
    cout<<ans<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
