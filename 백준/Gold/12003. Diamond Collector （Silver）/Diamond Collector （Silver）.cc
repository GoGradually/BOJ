#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10

using namespace std;

void Solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int left = 0, right = 0;
    multiset<pair<int, int>> correct;
    while (right < n) {
        if (arr[right] - arr[left] <= k) {
            correct.insert({left, right+1});
            right++;
        } else {
            left++;
        }
    }
    vector<int> d(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        auto it = correct.lower_bound({i + 1, 0});
        if (it == correct.begin()) continue;
        it--;
        d[i] = d[i + 1];
        if (it->first < i) continue;
        d[i] = max(d[i], it->second - it->first);
    }
    int ans = 0;
    for (auto it = correct.begin(); it != correct.end(); it++) {
        ans = max(ans, it->second - it->first + d[it->second]);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) Solve();
    return 0;
}