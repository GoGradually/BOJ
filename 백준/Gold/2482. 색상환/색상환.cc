#include <bits/stdc++.h>

using namespace std;
long long dp[1001][1001][2][2];
int n, k;
long long go(int index, int remain,int before, int check) {
	if (dp[index][remain][check][before] != -1) return dp[index][remain][check][before];
	if (index == n) {
		if (remain == 0 && !(check==1&&before==1)) {
			return dp[index][remain][check][before] = 1;
		}
		return dp[index][remain][check][before] = 0;
	}
	long long ans = 0;
	if (!before && remain>0) {
		ans += go(index + 1, remain - 1, true, check);
		ans %= 1000000003;
	}
	ans += go(index + 1, remain, false, check);
	ans %= 1000000003;
	return dp[index][remain][check][before] = ans;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	memset(dp, -1, sizeof(dp));
	cin >> n >> k;
	cout << (go(1, k, false, 0) + go(1, k - 1, true, 1)) % 1000000003;
	return 0;
}