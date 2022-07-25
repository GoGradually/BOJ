#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> g[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n-1; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back(make_pair(c, b));
		g[b].push_back(make_pair(c, a));
	}
	for (int i = 0; i < m; i++)
	{
		int stp, dest;
		cin >> stp >> dest;
		vector<int> check(n + 1, -1);
		check[stp] = 0;
		queue<int> bfsQ;
		bfsQ.push(stp);
		while (!bfsQ.empty()) {
			int now = bfsQ.front();
			bfsQ.pop();
			for (int i = 0; i < g[now].size(); i++)
			{
				int next = g[now][i].second;
				int dist = g[now][i].first;
				if (check[next] == -1) {
					check[next] = check[now] + dist;
					bfsQ.push(next);
				}
			}
		}
		cout << check[dest] << '\n';
	}
	return 0;
}