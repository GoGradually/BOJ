#include <bits/stdc++.h>

using namespace std;
int arr[101][101];
int check[101][101];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	memset(check, -1, sizeof(check));
	int n, m, t;
	cin >> n >> m >> t;
	int swordX, swordY;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 2)
			{
				swordX = i, swordY = j;
			}
		}
	}
	//n-i-1, m-1-j
	check[0][0] = 0;
	queue<pair<int, int>> bfsq;
	bfsq.push(make_pair(0, 0));
	while (!bfsq.empty()) {
		int x, y;
		tie(x, y) = bfsq.front();
		bfsq.pop();
		for (int k = 0; k < 4; k++)
		{
			int p = x + dx[k], q = y + dy[k];
			if (p >= 0 && p < n && q >= 0 && q < m) {
				if (arr[p][q]!=1&&check[p][q] == -1) {
					bfsq.push(make_pair(p, q));
					check[p][q] = check[x][y] + 1;
				}
			}
		}
	}
	int ans = t * 2;
	if (check[n - 1][m - 1] != -1) {
		ans = check[n - 1][m - 1];
	}
	if (check[swordX][swordY]!=-1&&ans > check[swordX][swordY] + m - swordY - 1 + n - swordX - 1)ans = check[swordX][swordY] + m - swordY - 1 + n - swordX - 1;
	if (ans > t)cout << "Fail\n";
	else {
		cout << ans << '\n';
	}
	return 0;
}