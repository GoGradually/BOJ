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
#define MOD 998244353LL
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;
struct disjointSet {
    vector<int> parent, rank;
    disjointSet(int n) : rank(n, 1), parent(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int n) {
        if (parent[n] == n) return n;
        return parent[n] = find(parent[n]);
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
    disjointSet uf(n);
    int ans = 0;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (ans == 0 && uf.find(a) == uf.find(b)) {
            ans = i + 1;
        } else {
            uf.merge(a, b);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
