#include <bits/stdc++.h>
using namespace std;

vector<int> g[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int a = 0, b = 0;
	int ans = 2100000000;
	for (int i = 1; i < n; i++)
	{
		for (int j = i+1; j <= n; j++)
		{
			vector<int> check(n + 1, -1);
			check[i] = 0;
			check[j] = 0;
			queue<int> bfsQ;
			bfsQ.push(i);
			bfsQ.push(j);
			while (!bfsQ.empty()) {
				int now = bfsQ.front();
				bfsQ.pop();
				for (int k = 0; k < g[now].size(); k++)
				{
					int next = g[now][k];
					if (check[next] == -1) {
						check[next] = check[now] + 1;
						bfsQ.push(next);
					}
				}
			}
			int ret = 0;
			for (int k = 1; k <= n; k++)
			{
				ret += check[k] * 2;
			}
			if (ret < ans) { 
				ans = ret;
				a = i;
				b = j;
			}
		}
	}
	cout << a << ' ' << b << ' ' << ans << '\n';
	return 0;
}