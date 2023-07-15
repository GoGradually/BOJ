#include <bits/stdc++.h>
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10LL
// #define int long long
const ll MOD = 1000000007LL;

// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

ll arr[10];

void cal(int x, ll tag) {
    while (x > 0) {
        arr[x % 10] += tag;
        x /= 10;
    }
}

void Solve() {
    int l, r;
    cin >> l >> r;
    ll tag = 1;
    while (l <= r) {
        while (l % 10 != 0 && l <= r) {
            cal(l, tag);
            l++;
        }
        while (r % 10 != 9 && l <= r) {
            cal(r, tag);
            r--;
        }
        if (l > r) break;
        l /= 10;
        r /= 10;
        for (int i = 0; i < 10; i++) {
            arr[i] += (r - l + 1) * tag;
        }
        tag *= 10;
    }
    ll ans = 0;
    for (ll i = 0; i < 10; i++) {
        ans += arr[i] * i;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--) Solve();
    return 0;
}