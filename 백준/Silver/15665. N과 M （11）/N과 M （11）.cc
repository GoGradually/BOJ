#include <bits/stdc++.h>

using namespace std;

int n, m;

void go(vector<int>& arr,vector<int>& ans, int index) {
	if (ans.size()==m) {
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}
	if (index == arr.size())return;
	ans.push_back(arr[index]);
	go(arr, ans, 0);
	ans.pop_back();
	go(arr, ans, index + 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	vector<int> ans;
	go(arr, ans, 0);
	return 0;
}