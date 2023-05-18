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
    vector<int> parent, rank, size;
    DisjointSet(int n) : parent(n), rank(n, 1), size(n, 1) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int now) {
        if (parent[now] == now) return now;
        return parent[now] = find(parent[now]);
    }
    int findSize(int now) {
        now = find(now);
        return size[now];
    }
    void merge(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;
        if (rank[u] < rank[v]) swap(u, v);
        parent[v] = u;
        size[u] += size[v];
        if (rank[u] == rank[v]) rank[u]++;
    }
};

void Solve() {
    int n, q;
    cin >> n >> q;
    DisjointSet uf(n + 1);
    priority_queue<pair<int, pair<int, int>>> pq;
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        pq.push({c, {a, b}});
    }
    vector<tuple<int, int, int>> query;
    vector<int> ans(q);
    for (int i = 0; i < q; i++) {
        int k, v;
        cin >> k >> v;
        query.push_back({k, v, i});
    }
    sort(query.begin(), query.end(), greater<tuple<int, int, int>>());
    for (int i = 0; i < q; i++) {
        int nowK, nowV, nowI;
        tie(nowK, nowV, nowI) = query[i];
        while (!pq.empty() && pq.top().first >= nowK) {
            uf.merge(pq.top().second.first, pq.top().second.second);
            pq.pop();
        }
        ans[nowI] = uf.findSize(nowV) - 1;
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--) Solve();
    return 0;
}
