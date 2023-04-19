#include <bits/stdc++.h>
#include <array>
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10LL
const ll MOD = 998244353;
using namespace std;

ll n, m;

array<ll, 3> extend_euclid(ll a, ll b) {
    array<ll, 3> x = {1, 0, a};
    array<ll, 3> y = {0, 1, b};
    while (y[2] > 0) {
        ll k = x[2] / y[2];
        for (int i = 0; i < 3; i++) {
            x[i] -= y[i] * k;
        }
        swap(x, y);
    }
    return x;
}

ll inv(ll a, ll b) {
    array<ll, 3> x = extend_euclid(a, b);
    if (x[2] != 1) return -1;
    return x[0] + (x[0] < 0 )* b;
}

void Solve() {
    cin >> n >> m;
    cout << n - m << ' ' << inv(m, n) << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) Solve();
    return 0;
}