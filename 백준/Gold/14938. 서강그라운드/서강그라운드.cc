#include <bits/stdc++.h>
using namespace std;
int n, m, r;
vector<int> item(101);
vector<pair<int, int>> g[101];
int INF = 1000000000;
int go(int index) {
    priority_queue<pair<int, int>> pq;
    vector<int> dist(n + 1, INF);
    dist[index] = 0;
    pq.push(make_pair(dist[index], index));
    while (!pq.empty()) {
        int nowDist = -pq.top().first, nowIndex = pq.top().second;
        pq.pop();
        for (int i = 0; i < g[nowIndex].size(); i++) {
            int next = g[nowIndex][i].second, way = g[nowIndex][i].first;
            if (dist[next] > dist[nowIndex] + way) {
                dist[next] = dist[nowIndex] + way;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] <= m) ret += item[i];
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++) {
        cin >> item[i];
    }
    for (int i = 0; i < r; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back(make_pair(c, b));
        g[b].push_back(make_pair(c, a));
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int value = go(i);
        ans = ans < value ? value : ans;
    }
    cout << ans << '\n';
    return 0;
}