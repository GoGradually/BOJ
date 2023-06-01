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

vector<ll> flavor;
vector<int> spicy;

template <class T>
class seg_tree {
   private:
    vector<int> tree;
    int tree_size;

   public:
    seg_tree(int n) {
        int h = (int)ceil(log2(n));
        tree_size = (1 << (h + 1));
        tree.resize(tree_size);
    }
    int cal(int x, int y) { return max(x, y); }
    void recalculate(int node) {
        tree[node] = cal(tree[node * 2 + 1], tree[node * 2 + 2]);
    }
    void build(int node, int left, int right) {
        if (left == right) {
            tree[node] = spicy[left];
            return;
        }
        int mid = (left + right) / 2;
        build(node * 2 + 1, left, mid);
        build(node * 2 + 2, mid + 1, right);
        recalculate(node);
    }
    void update(int node, int left, int right, int x, int y) {
        if (x < left || x > right) return;
        if (left == right) {
            tree[node] = y;
            return;
        }
        int mid = (left + right) / 2;
        update(node * 2 + 1, left, mid, x, y);
        update(node * 2 + 2, mid + 1, right, x, y);
        recalculate(node);
    }
    int query(int node, int left, int right, int x, int y) {
        if (y < left || x > right) return 0;
        if (left >= x && y >= right) return tree[node];
        int mid = (left + right) / 2;
        int lVal = query(node * 2 + 1, left, mid, x, y);
        int rVal = query(node * 2 + 2, mid + 1, right, x, y);
        return cal(lVal, rVal);
    }
};

void Solve() {
    int n;
    ll m;
    cin >> n >> m;
    seg_tree<int> segTree(n);
    flavor.resize(n + 1);
    spicy.resize(n + 1);
    vector<ll> psum(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> flavor[i] >> spicy[i];
        psum[i] = psum[i - 1] + flavor[i];
    }
    segTree.build(0, 1, n);
    int ans = INF;
    int left = 0, right = 1;
    while (right <= n) {
        if (psum[right] - psum[left] < m) {
            right++;
            continue;
        }
        ans = min(ans, segTree.query(0, 1, n, left + 1, right));
        left++;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--) Solve();
    return 0;
}
