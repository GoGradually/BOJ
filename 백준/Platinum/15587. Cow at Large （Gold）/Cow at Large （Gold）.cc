#include <bits/stdc++.h>
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
/*
#include "atcoder/modint.hpp"
using mint = atcoder::modint998244353;
*/

using namespace std;

vector<int> g[100001];
vector<int> leafDist(100001, -1), rootDist(100001, -1);
int depthCheck(int node) {
    if (g[node].size() == 1) {
        return 0;
    }
    leafDist[node] = INF;
    for (int i = 0; i < g[node].size(); i++) {
        int next = g[node][i];
        if (leafDist[next] == -1) {
            int visit = depthCheck(next);
            visit++;
            leafDist[node] = min(visit, leafDist[node]);
        }
    }
    return leafDist[node];
}
int go(int node) {}
void Solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    depthCheck(k);
    queue<int> bfsQ;
    bfsQ.push(k);
    rootDist[k] = 0;
    int ans = 0;
    while (!bfsQ.empty()) {
        int now = bfsQ.front();
        bfsQ.pop();
        for (auto &&next : g[now]) {
            if (rootDist[next] == -1) {
                rootDist[next] = rootDist[now] + 1;
                if (rootDist[next] >= leafDist[next]) {
                    ans++;
                    continue;
                } else {
                    bfsQ.push(next);
                }
            }
        }
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
