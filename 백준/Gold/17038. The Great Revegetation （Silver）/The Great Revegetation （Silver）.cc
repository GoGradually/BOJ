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

vector<pair<int, int>> g[100001];

void Solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        char a;
        int p, q;
        cin >> a >> p >> q;
        p--;
        q--;
        if (a == 'S') {
            g[p].push_back({q, 1});
            g[q].push_back({p, 1});
        } else {
            g[p].push_back({q, -1});
            g[q].push_back({p, -1});
        }
    }
    int cnt = 0;
    vector<int> check(n, -1);
    for (int i = 0; i < n; i++) {
        if (check[i] == -1) {
            cnt++;
            check[i] = cnt;
            queue<int> bfsQ;
            vector<int> color(n, -1);
            color[i] = 0;
            bfsQ.push(i);
            while (!bfsQ.empty()) {
                int now = bfsQ.front();
                bfsQ.pop();
                for (auto &&next : g[now]) {
                    if (check[next.first] == -1) {
                        check[next.first] = cnt;
                        if (next.second == 1) {
                            color[next.first] = color[now];
                        } else {
                            color[next.first] = 1 - color[now];
                        }
                        bfsQ.push(next.first);
                    } else if (check[next.first] == cnt) {
                        if (next.second == 1) {
                            if (color[now] != color[next.first]) {
                                cout << 0 << '\n';
                                return;
                            }
                        } else {
                            if (color[now] == color[next.first]) {
                                cout << 0 << '\n';
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << 1;
    for (int i = 0; i < cnt; i++) {
        cout << 0;
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--) Solve();
    return 0;
}
