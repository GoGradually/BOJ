#include <bits/stdc++.h>
using namespace std;

vector<int> g[101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	priority_queue<long long> pq;
	for (int i = 0; i < n; i++)
	{
		long long temp;
		cin >> temp;
		pq.push(-temp);
	}
	long long ans = 0;
	while (pq.size() != 1) {
		long long a = -pq.top();
		pq.pop();
		long long b = -pq.top();
		pq.pop();
		long long c = a + b;
		pq.push(-c);
		ans += c;
	}
	cout << ans << '\n';
	return 0;
}