#include <bits/stdc++.h>

using namespace std;
int dx[4] = { 0, -1, 0, 1 };
int dy[4] = { -1, 0, 1, 0 };
vector<string> arr(5);

int go(int index, int remain, vector<vector<int>>& check) {
	if (index==25 || remain == 0) {
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (check[i][j] == 1) {
					int cnt = 1;
					int som = 0;
					if (arr[i][j] == 'S')som++;
					queue<pair<int, int>> bfsQ;
					bfsQ.push(make_pair(i, j));
					int bfsCheck[5][5];
					memset(bfsCheck, 0, sizeof(bfsCheck));
					bfsCheck[i][j] = 1;
					while (!bfsQ.empty()) {
						int x, y;
						tie(x, y) = bfsQ.front();
						bfsQ.pop();
						for (int k = 0; k < 4; k++)
						{
							int p = x + dx[k], q = y + dy[k];
							if (p >= 0 && p < 5 && q >= 0 && q < 5 && bfsCheck[p][q] == 0 && check[p][q] == 1) {
								cnt++;
								if (arr[p][q] == 'S')som++;
								bfsQ.push(make_pair(p, q));
								bfsCheck[p][q] = 1;
							}
						}
					}
					if (cnt == 7 && som >= 4) return 1;
					else return 0;
				}
			}
		}
		return 0;
	}
	int x = index / 5;
	int y = index % 5;
	int ret = 0;
	check[x][y] = 1;
	ret += go(index + 1, remain - 1, check);
	check[x][y] = 0;
	ret += go(index + 1, remain, check);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<vector<int>> check;
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
		vector<int> temp(5, 0);
		check.push_back(temp);
	}
	int ans = go(0, 7, check);
	cout << ans << '\n';
	return 0;
}