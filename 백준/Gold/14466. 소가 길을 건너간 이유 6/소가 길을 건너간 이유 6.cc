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

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void Solve() {
    int n, k, r;
    cin >> n >> k >> r;
    vector<pair<int, int>> road[101][101];
    for (int i = 0; i < r; i++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        road[--r1][--c1].push_back({--r2, --c2});
        road[r2][c2].push_back({r1, c1});
    }
    vector<pair<int, int>> cow;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        cow.push_back({--a, --b});
    }
    int check[101][101];
    int cnt = 0;
    memset(check, 0, sizeof(check));
    for (int i = 0; i < k; i++) {
        int a, b;
        tie(a, b) = cow[i];
        if (check[a][b] != 0) continue;
        cnt++;
        queue<pair<int, int>> bfsQ;
        bfsQ.push({a, b});
        check[a][b] = cnt;
        while (!bfsQ.empty()) {
            int x, y;
            tie(x, y) = bfsQ.front();
            bfsQ.pop();
            for (int t = 0; t < 4; t++) {
                int p = x + dx[t], q = y + dy[t];
                bool ok = true;
                for (int u = 0; u < road[x][y].size(); u++) {
                    if (p == road[x][y][u].first && q == road[x][y][u].second) {
                        ok = false;
                    }
                }
                if (!ok) continue;
                if (p >= 0 && p < n && q >= 0 && q < n && check[p][q] == 0) {
                    check[p][q] = cnt;
                    bfsQ.push({p, q});
                }
            }
        }
    }
    vector<int> cowConnect(cnt + 1), psum(cnt + 2);
    for (int i = 0; i < k; i++) {
        int x, y;
        tie(x, y) = cow[i];
        cowConnect[check[x][y]]++;
    }
    ll ans = 0;
    for (int i = 0; i < cnt + 1; i++) {
        psum[i + 1] = psum[i] + cowConnect[i];
        ans += psum[i] * cowConnect[i];
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) Solve();
    return 0;
}
