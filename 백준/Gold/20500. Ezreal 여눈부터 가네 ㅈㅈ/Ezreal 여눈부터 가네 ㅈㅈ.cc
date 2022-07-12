#include <bits/stdc++.h>

using namespace std;

long long dp[1516][1516];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	long long mod = 1000000007;
	long long n, cnt1, val, ans = 0;
	cin >> n;
	dp[0][0] = 1;
	for (int i = 1; i < n; i++)
	{
		dp[i][0] = 1;
		for (int j = 1; j <=i; j++)
		{
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j])%mod;
		}
	}
	val = n + 4;
	cnt1 = n - 1;
	while (cnt1 >= 0) {
		if (val % 3 == 0) {
			ans += dp[n - 1][cnt1];
			ans %= mod;
		}
		val += 4;
		cnt1--;
	}
	cout << ans << '\n';
	return 0;
}