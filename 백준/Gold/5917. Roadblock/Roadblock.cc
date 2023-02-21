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
#define MOD 998244353
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;

int g[101][101];

vector<int> chase(101, 0);

int dijkstra(int n){
    vector<int> dist(101, INF);
    dist[1] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        int now = pq.top().second;
        int ndist = -pq.top().first;
        pq.pop();
        for (int next = 1; next<=n; next++) {
            if(ndist + g[now][next] < dist[next]){
                dist[next] = g[now][next] + dist[now];
                pq.push({-dist[next], next});
                chase[next] = now;
            }
        }
    }
    return dist[n];
}
void solve() {
    int n, m;
    cin>>n>>m;
    for (int i = 0; i<=n; i++) {
        for (int j = 0; j<=n; j++) {
            g[i][j] = INF;
        }
    }
    for (int i = 0; i<m; i++) {
        int a, b, c;
        cin>>a>>b>>c;
        g[a][b] = c;
        g[b][a] = c;
    }
    int ans2 = dijkstra(n);
    int ch = n;
    vector<int> path;
    while (ch!= 0) {
        path.push_back(ch);
        ch = chase[ch];
    }
    int ans1 = 0;
    for (int i = 0; i<path.size()-1; i++) {
        g[path[i]][path[i+1]] *= 2;
        g[path[i+1]][path[i]] *= 2;
        int val = dijkstra(n);
        if(val > ans1) ans1 = val;
        g[path[i]][path[i+1]] /= 2;
        g[path[i+1]][path[i]] /= 2;
    }
    cout<<ans1-ans2<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
