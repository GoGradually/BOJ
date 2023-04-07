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
#define MOD 1000000007
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10

using namespace std;

vector<int> g[100001];

void Solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[--a].push_back(--b);
        g[b].push_back(a);
    }
    vector<int> check(n, -1);
    check[0] = 0;
    int cnt = 0;
    queue<int> bfsQ;
    bfsQ.push(0);
    while(!bfsQ.empty()){
        int now = bfsQ.front();
        bfsQ.pop();
        int val = 1;
        int req = 1;
        for (int next : g[now]) {
            if(check[next]==-1)req++;
        }
        while(val<req){
            val*=2;
            cnt++;
        }
        for (int next : g[now]) {
            if(check[next]==-1){
                check[next] = ++cnt;
                bfsQ.push(next);
            }
        }
    }
    cout<<cnt<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) Solve();
    return 0;
}
