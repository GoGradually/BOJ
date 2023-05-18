#include <bits/stdc++.h>
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
#define MOD 1000000007LL;
/*
#include "atcoder/modint.hpp"
using mint = atcoder::modint998244353;
*/

using namespace std;

vector<int> g[100001];
int check[100001];
int ans = INF;

struct DisjointSet {
    vector<int> parent, rank;
    DisjointSet(int n) : parent(n), rank(n, 1) {
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
        if (u == v) return;
        if (rank[u] < rank[v]) swap(u, v);
        parent[v] = u;
        if (rank[u] == rank[v]) rank[u]++;
    }
};

void Solve() {
    int n, q;
    cin >> n >> q;
    DisjointSet uf(n + 1);
    vector<int> arr(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> arr[i];
    }
    vector<tuple<int, int, int>> query(n - 1 + q);
    for (int i = n - 1 + q - 1; i >= 0; i--) {
        int a, b, c;
        cin >> a;
        if (a == 0) {
            cin >> b;
        } else {
            cin >> b >> c;
        }
        query[i] = {a, b, c};
    }
    vector<int> ans(q);
    int index = 0;
    for (int i = 0; i < query.size(); i++) {
        int a, b, c;
        tie(a, b, c) = query[i];
        if (a == 0) {
            uf.merge(b, arr[b]);
        } else {
            if (uf.find(b) == uf.find(c)) {
                ans[index] = 1;
            } else {
                ans[index] = 0;
            }
            index++;
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < q; i++) {
        cout << (ans[i] == 1 ? "YES" : "NO") << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--) Solve();
    return 0;
}
