#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> g[50001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back(make_pair(c, b));
		g[b].push_back(make_pair(c, a));
	}
	priority_queue<pair<int, int>> pq;
	int dist[50001];
	memset(dist, 0x3f3f3f3f3f3f, sizeof(dist));
	dist[1] = 0;
	pq.push(make_pair(0, 1));
	while (!pq.empty()) {
		int now = pq.top().second;
		pq.pop();
		for (int i = 0; i < g[now].size(); i++)
		{
			int next = g[now][i].second;
			int val = g[now][i].first;
			if (dist[next] > dist[now] + val) {
				dist[next] = dist[now] + val;
				pq.push(make_pair( - dist[next], next));
			}
		}
	}
	cout << dist[n] << '\n';
	return 0;
}