#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;

int n, m;
vector<pair<ll, int>> g[100001];

void solve() {
    cin >> n >> m;
    vector<bool> ok(n, true);
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t == 1 && i > 0 && i < n-1) {
            ok[i] = false;
        }
    }

    for (int i = 0; i < m; i++) {
        ll a, b, t;
        cin >> a >> b >> t;
        g[a].push_back(make_pair(t, b));
        g[b].push_back(make_pair(t, a));
    }
    vector<ll> dist(n+1, lINF);
    priority_queue<pair<ll, int>> pq;
    pq.push(make_pair(0, 0));
    dist[0] = 0;
    while (!pq.empty()) {
        int now = pq.top().second;
        ll nowD = -pq.top().first;
        pq.pop();
        if (nowD > dist[now] || !ok[now]) continue;
        for (int i = 0; i < g[now].size(); i++) {
            int next = g[now][i].second;
            ll cost = g[now][i].first;
            if (dist[now] != lINF && dist[next] > nowD + cost) {
                dist[next] = cost + nowD;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }
    if(dist[n-1] == lINF) cout<<-1<<'\n';
    else
    cout << dist[n-1] << '\n';
}

int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while (t--) solve();
    return 0;
}
