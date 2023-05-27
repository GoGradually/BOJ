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

vector<ll> tree, arr;

ll cal(ll val1, ll val2) { return val1 + val2; }
void recalculate(int node) {
    tree[node] = cal(tree[2 * node + 1], tree[2 * node + 2]);
}
void build(int node, int left, int right) {
    if (left == right) {
        tree[node] = arr[left];
    } else {
        int mid = (left + right) / 2;
        build(2 * node + 1, left, mid);
        build(2 * node + 2, mid + 1, right);
        recalculate(node);
    }
}
ll query(int node, int left, int right, int x, int y) {
    if (x > right || y < left) return 0;
    if (x <= left && right <= y) return tree[node];
    int mid = (left + right) / 2;
    ll lVal = query(node * 2 + 1, left, mid, x, y);
    ll rVal = query(node * 2 + 2, mid + 1, right, x, y);
    return cal(lVal, rVal);
}
void update(int node, int left, int right, int x, ll y) {
    if (x < left || x > right) {
        return;
    }
    if (left == right) {
        tree[node] = y;
        return;
    }
    int mid = (left + right) / 2;
    update(2 * node + 1, left, mid, x, y);
    update(2 * node + 2, mid + 1, right, x, y);
    recalculate(node);
}
void Solve() {
    int n;
    cin >> n;
    arr.resize(n + 1);
    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h + 1));
    tree.resize(tree_size);
    build(0, 1, n);
    vector<ll> ans(n+1);
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        ans[temp] += query(0, 1, n, temp + 1, n);
        arr[temp]++;
        update(0, 1, n, temp, arr[temp]);
    }
    ll psum = 0;
    for (int i = 0; i < n; i++) {
        cout << psum << '\n';
        psum += ans[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--) Solve();
    return 0;
}
