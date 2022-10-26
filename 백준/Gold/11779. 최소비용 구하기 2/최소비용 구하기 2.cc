#include <bits/stdc++.h>
#define MOD 1000000007LL
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;

vector<pair<int, int>> g[1001];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back(make_pair(c, b));
    }
    priority_queue<pair<int, int>> pq;
    int start, end;
    cin >> start >> end;
    vector<int> check(n + 1, INF), route(n + 1, 0);
    for (int i = 0; i <= n; i++) {
        route[i] = i;
    }

    check[start] = 0;
    pq.push(make_pair(-check[start], start));
    while (!pq.empty()) {
        int now = pq.top().second;
        int nowD = -pq.top().first;
        pq.pop();
        if(check[now] < nowD) continue;
        for (int i = 0; i < g[now].size(); i++) {
            int next = g[now][i].second;
            int dist = g[now][i].first;
            if (nowD + dist < check[next]) {
                check[next] = nowD + dist;
                route[next] = now;
                pq.push(make_pair(-check[next], next));
            }
        }
    }
    cout << check[end] << '\n';
    stack<int> stk;
    stk.push(end);
    while (route[end] != end) {
        stk.push(route[end]);
        end = route[end];
    }
    cout << stk.size() << '\n';
    while (!stk.empty()) {
        cout << stk.top() << ' ';
        stk.pop();
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
