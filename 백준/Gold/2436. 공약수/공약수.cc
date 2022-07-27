#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y) {
	if (x < y) swap(x, y);
	if (y == 0)return x;
	return gcd(y, x % y);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int x, y;
	cin >> x >> y;
	int a, b;
	int t = 1;
	int ansx = x, ansy = y;
	for (int i = 1; i <= y/x; i++)
	{
		a = x * i;
		b = y / i;
		if (y % i != 0)continue;
		if (gcd(a, b)==x&&a + b < ansx + ansy) {
			ansx = a;
			ansy = b;
		}
	}
	cout << ansx << ' ' << ansy;
	return 0;
}