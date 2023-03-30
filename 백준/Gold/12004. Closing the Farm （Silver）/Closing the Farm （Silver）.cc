#include <algorithm>
#include <array>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define MOD 1000000007
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10

using namespace std;

vector<int> g[200001];
int check[200001];
bool open[3001];
void solve() {
    memset(open, true, sizeof(open));
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> closed(n);
    for (int i = 0; i < n; i++) {
        cin >> closed[i];
    }
    for (int i = 0; i < n; i++) {
        memset(check, -1, sizeof(check));
        check[closed[n-1]] = 1;
        queue<int> bfsQ;
        bfsQ.push(closed[n-1]);
        while (!bfsQ.empty()) {
            int now = bfsQ.front();
            bfsQ.pop();
            for (int i = 0; i < g[now].size(); i++) {
                int next = g[now][i];
                if (open[next] && check[next] == -1) {
                    check[next] = 1;
                    bfsQ.push(next);
                }
            }
        }
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (open[i+1] && check[i + 1] == -1) ok = false;
        }
        if (ok)
            cout << "YES\n";
        else
            cout << "NO\n";
        open[closed[i]] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
