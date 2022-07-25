#include <bits/stdc++.h>
using namespace std;

int n, start, dest;
vector<tuple<int, int, int>> g[100001][2];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> start >> dest;
	for (int i = 0; i < n-1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[a][0].push_back({ c, b, 0 });
		g[b][0].push_back({ c, a, 0 });
		g[a][1].push_back({ c, b, 1 });
		g[b][1].push_back({ c, a, 1 });
		g[a][0].push_back({ 0, b, 1 });
		g[b][0].push_back({ 0, a, 1 });
	}
	priority_queue<pair<int, pair<int, int>>> pq;
	int dist[100001][2];
	for (int i = 0; i < 100001; i++)
	{
		dist[i][0] = 2100000000;
		dist[i][1] = 2100000000;
	}
	pq.push(make_pair(0, make_pair(start, 0)));
	dist[start][0] = 0;
	while (!pq.empty()) {
		int nDist = -pq.top().first;
		pair<int, int> now = pq.top().second;
		pq.pop();
		for (auto next : g[now.first][now.second])
		{
			int nextD, nextVertex, nextTier;
			tie(nextD, nextVertex, nextTier) = next;
			if (dist[nextVertex][nextTier] > nDist + nextD) {
				dist[nextVertex][nextTier] = nDist + nextD;
				pq.push(make_pair(-dist[nextVertex][nextTier], make_pair(nextVertex, nextTier)));
			}
		}
	}
	cout << min(dist[dest][0], dist[dest][1]) << '\n';
	return 0;
}