#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;

vector<pair<ll, int>> g[100001];
int cnt = 1;

struct DisjointSet{
    vector<int> parent, rank;
    DisjointSet(int n) : parent(n), rank(n, 1){
        for (int i = 0; i<n; i++) {
            parent[i] = i;
        }
    }
    int find(int now){
        if(parent[now] == now) return now;
        return parent[now] = find(parent[now]);
    }
    void merge(int u, int v){
        u = find(u), v = find(v);
        if(rank[u] < rank[v]) swap(u, v);
        parent[v] = u;
        if(rank[u]==rank[v])rank[u]++;
    }
};

void solve() {
    cout<<"Scenario "<<cnt++<<":\n";
    int n, k, m;
    cin>>n>>k;
    DisjointSet uf(n);
    for(int i = 0; i<k; i++){
        int a, b;
        cin>>a>>b;
        uf.merge(a, b);
    }
    cin>>m;
    for(int i = 0; i<m; i++){
        int a, b;
        cin>>a>>b;
        if(uf.find(a)==uf.find(b)){
            cout<<1<<'\n';
        }else{
            cout<<0<<'\n';
        }
    }
    cout<<'\n';
}

int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while (t--) solve();
    return 0;
}
