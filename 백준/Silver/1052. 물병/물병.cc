#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	int temp;
	while (k > 0) {
		temp = 1;
		while (temp * 2 <= n) {
			temp *= 2;
		}
		n -= temp;
		k--;
		if (n == 0) {
			temp = 0;
			break;
		}
	}
	cout << temp - n;
	return 0;
}