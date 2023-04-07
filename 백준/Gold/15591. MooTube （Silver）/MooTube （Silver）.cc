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

vector<pair<int, int>> g[10001];

void Solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({c, b});
        g[b].push_back({c, a});
    }
    for (int i = 0; i < q; i++) {
        int k, start;
        cin >> k >> start;
        vector<int> check(n + 1);
        check[start] = 1;
        int cnt = 0;
        queue<int> bfsQ;
        bfsQ.push(start);
        while (!bfsQ.empty()) {
            int now = bfsQ.front();
            bfsQ.pop();
            for (auto &&next : g[now]) {
                if (next.first < k) continue;
                if (check[next.second] == 0) {
                    bfsQ.push(next.second);
                    check[next.second] = 1;
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) Solve();
    return 0;
}
