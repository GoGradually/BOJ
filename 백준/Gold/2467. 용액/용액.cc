#include <bits/stdc++.h>
#define MOD 1000000007LL
#define ll long long
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
    pair<int, int> ans;
    int val = INF;
    if (arr[0] >= 0) {
        cout << arr[0] << ' ' << arr[1] << '\n';
        return;
    }
    if (arr[n - 1] <= 0) {
        cout << arr[n - 2] << ' ' << arr[n - 1] << '\n';
        return;
    }
    for (int i = 0; i < n; i++) {
        auto g2 = lower_bound(arr.begin(), arr.end(), -arr[i]);
        int index = g2 - arr.begin();
        if (index != n && index >= 0 && index != i &&
            abs(arr[i] + arr[index]) < val) {
            val = abs(arr[i] + arr[index]);
            ans = {arr[i], arr[index]};
        }
        index--;
        if (index != n && index >= 0 && index != i &&
            abs(arr[i] + arr[index]) < val) {
            val = abs(arr[i] + arr[index]);
            ans = {arr[i], arr[index]};
        }
        index--;
        if (index != n && index >= 0 && index != i &&
            abs(arr[i] + arr[index]) < val) {
            val = abs(arr[i] + arr[index]);
            ans = {arr[i], arr[index]};
        }
    }
    cout << ans.first << ' ' << ans.second << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
