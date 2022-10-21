#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
#define MOD 998244353LL
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;

struct disjointSet {
    vector<int> parent, rank;
    disjointSet(int n) : parent(n), rank(n, 1) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int now) {
        if (parent[now] == now) return now;
        return parent[now] = find(parent[now]);
    }
    void merge(int u, int v) {
        u = find(u), v = find(v);
        if (rank[u] < rank[v]) swap(u, v);
        parent[v] = u;
        if (rank[u] == rank[v]) rank[u]++;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    disjointSet uf(n + 1);
    for (int i = 0; i < m; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 0) uf.merge(a, b);
        if (t == 1) {
            if (uf.find(a) == uf.find(b))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
