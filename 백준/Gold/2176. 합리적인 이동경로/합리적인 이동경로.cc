#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define MOD 1000000000LL
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;

long long dist[1001];
long long dp[1001];
vector<pair<int, int>> g[1001];
ll go (int x){
    ll &ans = dp[x];
    if(ans != -1) return ans;
    ans = 0;
    if(x==2) return ans = 1;
    for (int i = 0; i<g[x].size(); i++) {
        if(dist[x] > dist[g[x][i].second])
            ans += go(g[x][i].second);
    }
    return ans;
}
void solve() {
    int n, m;
    cin>>n>>m;
    for (int i = 1; i<=n; i++) {
        dist[i] = lINF;
    }
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i<m; i++) {
        int a, b, c;
        cin>>a>>b>>c;
        g[a].push_back({c, b});
        g[b].push_back({c, a});
    }
    priority_queue<pair<int, int>> pq;
    pq.push({0, 2});
    dist[2] = 0;
    while (!pq.empty()) {
        int now = pq.top().second;
        pq.pop();
        for (int i = 0; i<g[now].size(); i++) {
            int next = g[now][i].second;
            int nextD = g[now][i].first;
            if(dist[next] > dist[now] + nextD){
                dist[next] = dist[now] + nextD;
                pq.push({-dist[next], next});
            }
        }
    }
    cout<<go(1)<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
