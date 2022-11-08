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
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int>(n + 1, INF));
    for (int i = 0; i < m; i++) {
        int c, a, b;
        cin >> a >> b >> c;
        if (c == 1) {
            g[a][b] = 0;
            g[b][a] = 0;
        } else {
            g[a][b] = 0;
            g[b][a] = 1;
        }
    }
    for (int k = 1; k <= n; k++) {
        g[k][k] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (g[i][j] > g[i][k] + g[k][j]) g[i][j] = g[i][k] + g[k][j];
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int s, e;
        cin >> s >> e;
        cout << g[s][e] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
