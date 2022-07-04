#include <iostream>
#include <cstring>
using namespace std;
int dp[101][101];
int main()
{
	int n, m;
	int inf = 0x3f3f3f3f;
	cin >> n>>m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = inf;
			if (i == j) dp[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		dp[a][b] = 1;
		dp[b][a] = 1;
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (dp[i][j] > dp[i][k] + dp[k][j])
					dp[i][j] = dp[i][k] + dp[k][j];
			}
		}
	}
	int ans = inf;
	int human = 0;
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		for (int j = 1; j <= n; j++)
		{
			sum += dp[i][j];
		}
		if (ans > sum) {
			ans = sum;
			human = i;
		}
	}
	cout << human << '\n';
	return 0;
}