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
    for (int i = 0; i<m; i++) {
        int a, b, c;
        cin>>a>>b>>c;
        g[a].push_back(make_pair(c, b));
    }
    vector<ll> dist(n+1, lINF);
    int start, end;
    cin>>start>>end;
    dist[start] = 0;
    priority_queue<pair<ll, int>> pq;
    pq.push(make_pair(0,start));
    while (!pq.empty()) {
        int now = pq.top().second;
        ll nowD = -pq.top().first;
        pq.pop();
        if(nowD>dist[now])continue;
        for (int i = 0; i<g[now].size(); i++) {
            int next = g[now][i].second;
            ll cost = g[now][i].first;
            if(dist[next] > nowD + cost)
            {
                dist[next] = nowD + cost;
                pq.push(make_pair(-dist[next], next));
            }
        }
    }
    cout<<dist[end]<<'\n';
}

int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while (t--) solve();
    return 0;
}
