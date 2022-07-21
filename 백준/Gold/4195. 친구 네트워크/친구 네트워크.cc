#include <bits/stdc++.h>
using namespace std;
int n, m;
struct DisjointSet {
    vector<int> parent, rank;
    DisjointSet(int n) : parent(n), rank(n, 1) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int now) {
        if (parent[now] == now) {
            return now;
        }
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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        map<string, int> Friend;
        DisjointSet uf(200003);
        vector<int> cnt(200003, 1);
        int num = 0;
        int friendship;
        cin >> friendship;
        for (int i = 0; i < friendship; i++) {
            string str1, str2;
            cin >> str1 >> str2;
            if (Friend.count(str1) == 0) {
                Friend[str1] = ++num;
            }
            if (Friend.count(str2) == 0) {
                Friend[str2] = ++num;
            }
            int a = Friend[str1];
            int b = Friend[str2];
            int p = cnt[uf.find(a)];
            int q = cnt[uf.find(b)];
            if (!(uf.find(a) == uf.find(b))) {
                uf.merge(a, b);
                cnt[uf.find(a)] = p + q;
            }
            cout << cnt[uf.find(a)] << '\n';
        }
    }

    return 0;
}