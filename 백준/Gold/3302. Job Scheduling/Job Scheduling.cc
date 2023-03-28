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
 
ll n, d, m;
pair<ll, ll> arr[1000001];
 
bool check(ll x) {
    ll day = 1;
    ll cnt = 0;
    for (ll i = 0; i < m; i++) {
        if (arr[i].first > day) {
            day = arr[i].first;
            cnt = 0;
        }
        if (cnt == x) {
            cnt = 0;
            day++;
        }
        if (arr[i].first + d < day) {
            return false;
        }
        cnt++;
    }
    if (day > n) return false;
    return true;
}
void construct(ll x) {
    ll day = 1;
    ll cnt = 0;
    for (ll i = 0; i < m; i++) {
        while (cnt == x||day < arr[i].first) {
            cnt = 0;
            cout << 0 << '\n';
            day++;
        }
        cout << arr[i].second << ' ';
        cnt++;
    }
    for (; day <= n; day++) {
        cout << 0 << '\n';
    }
}
 
ll first_true(ll lo, ll hi) {
    hi++;
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}
 
void solve() {
    cin >> n >> d >> m;
    for (ll i = 0; i < m; i++) {
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }
    sort(arr, arr + m);
    ll ans = first_true(1, INF);
    cout << ans << '\n';
    construct(ans);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
