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
    vector<tuple<ll, ll, ll, ll>> arr(n);
    vector<ll> all_x;
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        arr[i] = {a, b, c, d};
        all_x.push_back(a);
        all_x.push_back(c);
    }
    sort(all_x.begin(), all_x.end());
    int i = 0;
    ll ans = 0;
    while (i < all_x.size()) {
        ll x = all_x[i];
        if (i > 0 && x == all_x[i - 1]) {
            i++;
            continue;
        }
        vector<pair<int, int>> y;
        for (int j = 0; j < arr.size(); j++) {
            int x1, y1, x2, y2;
            tie(x1, y1, x2, y2) = arr[j];
            if (x1 <= x && x < x2) {
                y.push_back({y2, 1});
                y.push_back({y1, -1});
            }
        }
        if (y.size() == 0) {
            i++;
            continue;
        }
        sort(y.begin(), y.end());
        int pos = 0;
        ll now_size = 0;
        while (pos < y.size()) {
            if (y[pos].second == -1) {
                pos++;
                continue;
            }
            int bottom = y[pos].first;
            int now_stack = y[pos].second;
            while (now_stack > 0) {
                now_stack += y[++pos].second;
            }
            int top = y[pos].first;
            now_size += top - bottom;
            pos++;
        }
        int j = i + 1;
        while (all_x[j] == all_x[i]) j++;
        ans += now_size * (all_x[j] - all_x[i]);
        i = j;
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
