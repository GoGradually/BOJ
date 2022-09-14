#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;

vector<pair<ll, int>> g[100001];

struct DisjointSet{
    vector<int> parent, rank;
    DisjointSet(int n) : parent(n), rank(n, 1){
        for (int i = 0; i<n; i++) {
            parent[i] = i;
        }
    }
    int find(int now){
        if(parent[now]==now) return now;
        return parent[now] = find(parent[now]);
    }
    void merge(int u, int v){
        u = find(u), v = find(v);
        if(u == v) return;
        if(rank[u] < rank[v])swap(u, v);
        parent[v] = u;
        if(rank[u]==rank[v])rank[u]++;
    }
};

void solve() {
    int n;
    cin>>n;
    DisjointSet uf(n);
    for(int i = 0; i<n-2; i++){
        int a, b;
        cin>>a>>b;
        uf.merge(a-1, b-1);
    }
    int prev = uf.find(0);
    for (int i = 1; i<n; i++) {
        if(prev!=uf.find(i)){
            cout<<prev+1<<' '<<i+1<<'\n';
            break;
        }
    }
}

int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t=1;
    while (t--) solve();
    return 0;
}
