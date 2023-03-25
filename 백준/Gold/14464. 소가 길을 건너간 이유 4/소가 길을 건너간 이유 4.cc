#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}
void solve() {
    int n, m;
    cin >> n >> m;
    multiset<int> ms;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ms.insert(a);
    }
    vector<pair<int, int>> arr(m);
    for (int i = 0; i < m; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end(), cmp);
    int ans = 0;
    for (int i = 0; i < m; i++) {
        auto it1 = ms.lower_bound(arr[i].first);
        auto it2 = ms.upper_bound(arr[i].second);
        if (it1 != it2) {
            ms.erase(it1);
            ans++;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}