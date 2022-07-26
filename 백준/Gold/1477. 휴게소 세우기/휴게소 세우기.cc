#include <bits/stdc++.h>
using namespace std;

int n, m, l;
vector<int> hugeso;
bool can(int T) {
	int now = 0;
	int index = 0;
	int remain = m;
	while (remain >= 0 && index<hugeso.size()) {
		if (remain > 0 && now + T < hugeso[index]) {
			now = now + T;
			remain--;
		}
		else if (hugeso[index] - now <= T) {
			now = hugeso[index++];
		}
		else break;
	}
	if (l - now <= T)return true;
	else return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> l;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		hugeso.push_back(a);
	}
	sort(hugeso.begin(), hugeso.end());
	hugeso.push_back(l);
	int left = 0, right = l;
	int mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (can(mid)) {
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}
	cout << left << '\n';
	return 0;
}