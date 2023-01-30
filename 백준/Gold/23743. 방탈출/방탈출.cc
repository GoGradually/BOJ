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

struct DisjointSet {
    vector<int> parent;
    vector<int> rank;
    DisjointSet(int n) : parent(n), rank(n, 1){
        for (int i = 0; i<n; i++) {
            parent[i] = i;
        }
    }
    int find(int n){
        if(parent[n] == n) return n;
        return parent[n] = find(parent[n]);
    }
    void merge(int u, int v){
        u = find(u), v = find(v);
        if(u == v) return;
        if(rank[v] > rank[u])swap(u, v);
        parent[v] = u;
        if(rank[u]==rank[v]) rank[u]++;
    }
};

void solve() {
    int n, m;
    cin>>n>>m;
    vector<tuple<int, int, int>> edge;
    for (int i = 0; i<m; i++) {
        int a, b, c;
        cin>>a>>b>>c;
        edge.push_back({c, a, b});
    }
    for (int i = 0; i<n; i++) {
        int a;
        cin>>a;
        edge.push_back({a, 0, i+1});
    }
    sort(edge.begin(), edge.end());
    int ans = 0;
    DisjointSet uf(n+1);
    for (int i = 0; i<edge.size(); i++) {
        int c, a, b;
        tie(c, a, b) = edge[i];
        if(uf.find(a) == uf.find(b)) continue;
        uf.merge(a, b);
        ans+=c;
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
