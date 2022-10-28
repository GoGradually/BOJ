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
    long long val = lINF;
    int left = 0, right = n - 1;
    while (left < right) {
        if (val > abs(arr[left] + arr[right])) {
            val = abs(arr[left] + arr[right]);
            ans = {arr[left], arr[right]};
        }
        if (arr[left] + arr[right] > 0) {
            right--;
        } else if (arr[left] + arr[right] < 0) {
            left++;
        } else {
            break;
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
