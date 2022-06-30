#include <bits/stdc++.h>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	vector<int> g[1001];
	vector<string> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++) {
			int diff = 0;
			for (int t = 0; t <k ; t++)
			{
				if (arr[i][t] != arr[j][t])diff++;
			}
			if (diff == 1) {
				g[i + 1].push_back(j + 1);
				g[j + 1].push_back(i + 1);
			}
		}
	}
	int start, dest;
	cin >> start >> dest;
	vector<int> check(1001, -1);
	check[start] = start;
	queue<int> bfsQ;
	bfsQ.push(start);
	while (!bfsQ.empty()) {
		int now = bfsQ.front();
		bfsQ.pop();
		for (int i = 0; i < g[now].size(); i++)
		{
			if (check[g[now][i]] == -1) {
				check[g[now][i]] = now;
				bfsQ.push(g[now][i]);
			}
		}
	}
	if (check[dest] == -1) {
		cout << -1 << '\n';
		return 0;
	}
	stack<int> pass;
	while (check[dest] != dest) {
		pass.push(dest);
		dest = check[dest];
	}
	pass.push(start);
	while (!pass.empty()) {
		cout << pass.top() << ' ';
		pass.pop();
	}
	return 0;
}