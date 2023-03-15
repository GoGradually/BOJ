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

vector<pair<int, int>> arr;
vector<ll> xUp(1, 0), xDown(1, 0), yUp(1, 0), yDown(1, 0);

bool ycmp(pair<int, int> &a, pair<int, int> &b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}
void solve() {
    int n;
    cin >> n;
    ll oneFence = 0;
    ll l = INF, r = 0, u = 0, d = INF;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        arr.push_back({a, b});
        l = min(l, a);
        r = max(r, a);
        u = max(u, b);
        d = min(d, b);
    }
    oneFence = (r - l) * (u - d);
    sort(arr.begin(), arr.end());
    l = INF, r = 0, u = 0, d = INF;
    for (int i = 0; i < n; i++) {
        ll a, b;
        tie(a, b) = arr[i];
        l = min(l, a);
        r = max(r, a);
        u = max(u, b);
        d = min(d, b);
        ll val = (r - l) * (u - d);
        xUp.push_back(val);
    }
    l = INF, r = 0, u = 0, d = INF;
    for (int i = n - 1; i >= 0; i--) {
        ll a, b;
        tie(a, b) = arr[i];
        l = min(l, a);
        r = max(r, a);
        u = max(u, b);
        d = min(d, b);
        ll val = (r - l) * (u - d);
        xDown.push_back(val);
    }
    sort(arr.begin(), arr.end(), ycmp);

    l = INF, r = 0, u = 0, d = INF;
    for (int i = 0; i < n; i++) {
        ll a, b;
        tie(a, b) = arr[i];
        l = min(l, a);
        r = max(r, a);
        u = max(u, b);
        d = min(d, b);
        ll val = (r - l) * (u - d);
        yUp.push_back(val);
    }
    l = INF, r = 0, u = 0, d = INF;
    for (int i = n - 1; i >= 0; i--) {
        ll a, b;
        tie(a, b) = arr[i];
        l = min(l, a);
        r = max(r, a);
        u = max(u, b);
        d = min(d, b);
        ll val = (r - l) * (u - d);
        yDown.push_back(val);
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, oneFence - xUp[i] - xDown[n - i]);
        ans = max(ans, oneFence - yUp[i] - yDown[n - i]);
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
