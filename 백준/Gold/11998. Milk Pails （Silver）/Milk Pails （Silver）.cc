#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void Solve() {
    int x, y, k, m;
    cin >> x >> y >> k >> m;
    map<pair<int, int>, int> pails;
    pails[{0, 0}] = 1;
    queue<pair<int, int>> bfsQ;
    bfsQ.push({0, 0});
    int ans = INF;
    while (!bfsQ.empty()) {
        int nowX, nowY;
        tie(nowX, nowY) = bfsQ.front();
        bfsQ.pop();
        if (pails[{nowX, y}] == 0) {
            pails[{nowX, y}] = pails[{nowX, nowY}] + 1;
            bfsQ.push({nowX, y});
            if (pails[{nowX, nowY}] <= k) ans = min(ans, abs(nowX + y - m));
        }
        if (pails[{x, nowY}] == 0) {
            bfsQ.push({x, nowY});
            pails[{x, nowY}] = pails[{nowX, nowY}] + 1;
            if (pails[{nowX, nowY}] <= k) ans = min(ans, abs(x + nowY - m));
        }
        if (pails[{0, nowY}] == 0) {
            pails[{0, nowY}] = pails[{nowX, nowY}] + 1;
            bfsQ.push({0, nowY});
            if (pails[{nowX, nowY}] <= k) ans = min(ans, abs(0 + nowY - m));
        }
        if (pails[{nowX, 0}] == 0) {
            pails[{nowX, 0}] = pails[{nowX, nowY}] + 1;
            bfsQ.push({nowX, 0});
            if (pails[{nowX, nowY}] <= k) ans = min(ans, abs(nowX + 0 - m));
        }
        if (nowX + nowY > x) {
            if (pails[{x, nowX + nowY - x}] == 0) {
                pails[{x, nowX + nowY - x}] = pails[{nowX, nowY}] + 1;
                bfsQ.push({x, nowX + nowY - x});
            }
        } else {
            if (pails[{nowX + nowY, 0}] == 0) {
                pails[{nowX + nowY, 0}] = pails[{nowX, nowY}] + 1;
                bfsQ.push({nowX + nowY, 0});
            }
        }
        if (nowX + nowY > y) {
            if (pails[{nowX + nowY - y, y}] == 0) {
                pails[{nowX + nowY - y, y}] = pails[{nowX, nowY}] + 1;
                bfsQ.push({nowX + nowY - y, y});
            }
        } else {
            if (pails[{0, nowX + nowY}] == 0) {
                pails[{0, nowX + nowY}] = pails[{nowX, nowY}] + 1;
                bfsQ.push({0, nowX + nowY});
            }
        }
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
