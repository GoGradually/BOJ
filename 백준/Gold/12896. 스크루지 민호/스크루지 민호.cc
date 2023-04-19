#include <bits/stdc++.h>

#include <array>
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10LL
const ll MOD = 998244353;
using namespace std;

vector<int> g[100001];

void Solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> check(n + 1, 0);
    check[1] = 1;
    queue<int> bfsQ;
    bfsQ.push(1);
    int start = 0;
    while (!bfsQ.empty()) {
        int now = bfsQ.front();
        bfsQ.pop();
        start = now;
        for (auto &&next : g[now]) {
            if (check[next] == 0) {
                check[next] = 1;
                bfsQ.push(next);
            }
        }
    }
    check.clear();
    check.resize(n + 1, -1);
    check[start] = 0;
    bfsQ.push(start);
    int mx = 0;
    while (!bfsQ.empty()) {
        int now = bfsQ.front();
        bfsQ.pop();
        start = now;
        for (auto &&next : g[now]) {
            if (check[next] == -1) {
                check[next] = check[now] + 1;
                mx = max(mx, check[next]);
                bfsQ.push(next);
            }
        }
    }
    cout << (mx + 1) / 2 << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) Solve();
    return 0;
}