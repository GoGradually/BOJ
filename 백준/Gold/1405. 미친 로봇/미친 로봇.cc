#include <bits/stdc++.h>

using namespace std;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
double per[4];

double dfs(int x, int y,int remain,double value, vector<vector<bool>> &ch) {
	if (remain == 0||value==0) {
		return value;
	}
	double ret = 0;
	for (int k = 0; k < 4; k++)
	{
		int p = x + dx[k], q = y + dy[k];
		if (ch[p][q]) continue;
		ch[p][q] = true;
		ret += dfs(p, q, remain - 1, value * per[k], ch);
		ch[p][q] = false;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.precision(11);
	double ans = 0;
	vector<vector<bool>> check;
	for (int i = 0; i < 29; i++)
	{
		vector<bool> temp(29, false);
		check.push_back(temp);
	}
	check[14][14] = true;
	int n;
	cin >> n >> per[0] >> per[1] >> per[2] >> per[3];
	for (int i = 0; i < 4; i++) per[i] /= 100;
	cout << dfs(14, 14, n, (double)1, check) << '\n';
	return 0;
}