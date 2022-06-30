#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int ans = 0;
	int n;
	cin >> n;
	vector<int> g[1001];
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
	}
	priority_queue<int> pq;
	for (int i = 1000; i >= 1; i--)
	{
		if (!g[i].empty()) {
			for (int j = 0; j < g[i].size(); j++)
			{
				pq.push(g[i][j]);
			}
		}
		if (!pq.empty()) {
			ans += pq.top();
			pq.pop();
		}
	}
	cout << ans << '\n';
	return 0;
}