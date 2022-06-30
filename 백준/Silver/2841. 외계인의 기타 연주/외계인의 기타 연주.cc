#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	stack<int> line[6];
	int n, p;
	cin >> n >> p;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		while (!line[a].empty()&&line[a].top() > b) {
			line[a].pop();
			ans++;
		}
		if (!line[a].empty() && line[a].top() == b)continue;
		line[a].push(b);
		ans++;
	}
	cout << ans << '\n';
	return 0;
}