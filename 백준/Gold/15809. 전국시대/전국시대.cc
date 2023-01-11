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


struct  disjointset{
    vector<int> parent, rank;
    disjointset(int n):parent(n), rank(n, 1){
        for (int i = 0; i<n; i++) {
            parent[i] = i;
        }
    }
    int find(int now){
        if(parent[now]==now)return now;
        return parent[now] = find(parent[now]);
    }
    void merge(int u, int v){
        u = find(u), v = find(v);
        if(u==v) return;
        if(rank[u] < rank[v]) swap(u, v);
        parent[v] = u;
        if(rank[u]==rank[v])rank[u]++;
    }
};

void solve() {
    int n, m;
    cin>>n>>m;
    disjointset uf(n);
    vector<int> soldier(n);
    for (int i = 0; i<n; i++) {
        cin>>soldier[i];
    }
    for (int i = 0; i<m; i++) {
        int o, p, q;
        cin>>o>>p>>q;
        p--;
        q--;
        p = uf.find(p), q = uf.find(q);
        if(o==1){
            uf.merge(p, q);
            soldier[uf.find(p)] = soldier[p] + soldier[q];
        }else{
            uf.merge(p, q);
            soldier[uf.find(p)] = abs(soldier[p] - soldier[q]);
        }
    }
    vector<int> ans;
    for (int i = 0; i<n; i++) {
        if(uf.find(i) == i&&soldier[i] != 0){
            ans.push_back(soldier[i]);
        }
    }
    sort(ans.begin(), ans.end());
    cout<<ans.size()<<'\n';
    for (int i = 0; i<ans.size(); i++) {
        cout<<ans[i]<<' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
