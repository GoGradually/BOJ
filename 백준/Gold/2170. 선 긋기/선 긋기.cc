#include <algorithm>
#include <array>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define MOD 998244353
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> arr(n);
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        arr[i] = {a, b};
    }
    sort(arr.begin(), arr.end());
    ll start = -lINF, end = -lINF;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].first > end) {
            ans += end - start;
            start = arr[i].first;
            end = arr[i].second;
        } else if (arr[i].first <= end) {
            end = max(end,arr[i].second);
        }
    }
    ans += end - start;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
