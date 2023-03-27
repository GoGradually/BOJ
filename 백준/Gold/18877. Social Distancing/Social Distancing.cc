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
#define MOD 1000000007
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10

using namespace std;

int n, m;
pair<ll, ll> arr[100001];

bool check(ll x) {
    int i = 0;
    int cnt = 1;
    ll now = arr[0].first;
    while (i < m) {
        if (arr[i].second >= now + x) {
            now = max(now + x, arr[i].first);
            cnt++;
        } else {
            i++;
        }
    }
    if (n > cnt) {
        return false;
    } else {
        return true;
    }
}

ll last_true(ll lo, ll hi) {
    lo--;
    while (lo < hi) {
        ll mid = lo + (hi - lo + 1) / 2;
        if (check(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    return lo;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr, arr + m);
    ll ans = last_true(0, lINF);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
