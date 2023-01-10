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
#define MOD 1000000000LL
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;


void solve() {
    int n;
    int m;
    cin>>n>>m;
    vector<vector<int>> arr(n, vector<int> (n));
    vector<int> route(m);
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            cin>>arr[i][j];
        }
    }
    for (int i = 0; i<m; i++) {
        cin>>route[i];
        route[i]--;
    }
    vector<int> check(n, 0);
    int cnt = 0;
    for (int i = 0; i<n; i++) {
        if(check[i] == 0){
            cnt+=1;
            queue<int> bfsQ;
            bfsQ.push(i);
            check[i] = cnt;
            while (!bfsQ.empty()) {
                int now = bfsQ.front();
                bfsQ.pop();
                for (int k = 0; k<n; k++) {
                    if(k==now) continue;
                    if(check[k] == 0 && arr[now][k] == 1){
                        check[k] = cnt;
                        bfsQ.push(k);
                    }
                }
            }
        }
    }
    bool ok = true;
    for (int i = 0; i<m-1; i++) {
        if(check[route[i]]!=check[route[i+1]]){
            ok = false;
        }
    }
    if(ok)cout<<"YES\n";
    else cout<<"NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
