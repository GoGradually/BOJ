#include <bits/stdc++.h>
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10LL
// #define int long long
const ll MOD = 1000000007LL;

// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

void Solve() {
    int x, y, d, t;
    cin >> x >> y >> d >> t;
    if (t >= d)
        cout << sqrt(x * x + y * y) << '\n';
    else {
        int i = 0;
        double ans = sqrt(x * x + y * y);
        while (true) {
            double now = sqrt(x * x + y * y) - i * d;
            now = abs(now);
            if (now >= 2 * t && now <= 2 * d)now = 2 * t;
            if (ans >= now + i * t)
                ans = now + i * t;
            else {
                break;
            }
            i++;
        }
        cout << ans << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed;
    cout.precision(9);
    int T = 1;
    while (T--) Solve();
    return 0;
}