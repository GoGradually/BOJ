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
#define MOD 1000000000LL
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;

void solve() {
    int m, n;
    cin>>m;
    vector<pair<int, int>> starlight(m);
    int p = -1, q = -1;
    for (int i = 0; i<m; i++) {
        int a, b;
        cin>>a>>b;
        if(p==-1)p = a, q = b;
        starlight[i] = {a-p, b-q};
    }
    cin>>n;
    vector<pair<int, int>> star(n);
    map<pair<int, int>, bool> check;
    for (int i = 0; i<n; i++) {
        int a, b;
        cin>>a>>b;
        star[i] = {a, b};
        check[{a, b}] = true;
    }
    int ans1, ans2;
    for (int i = 0; i<n; i++) {
        int x = star[i].first, y = star[i].second;
        bool ok = true;
        for (int j = 0; j<m; j++) {
            if(!check[{x+starlight[j].first, y+starlight[j].second}]) ok = false;
        }
        if(ok){
            ans1 = x - p, ans2 = y - q;
        }
    }
    cout<<ans1<<' '<<ans2<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
