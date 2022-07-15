#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	long long ans = 0;
	vector<long long> arr(1000001, 0);
	for (int i = 1; i <= 1000000; i++)
	{
		for (int j = 1; i*j <= 1000000; j++)
		{
			arr[i * j] += i;
		}
	}
	vector<long long> dp(1000001, 0);
	for (int i = 1; i <= 1000000; i++)
	{
		dp[i] = dp[i - 1] + arr[i];
	}
	while (t--) {
		int n;
		cin >> n;
		cout << dp[n] << '\n';
	}
	return 0;
}