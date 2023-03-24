#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> ans;
    sort(arr.begin(), arr.end(), greater<int>());
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= ans.size())ans.push_back(arr[i]);
    }
    cout << ans.size() << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}