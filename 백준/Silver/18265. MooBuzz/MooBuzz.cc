#include <bits/stdc++.h>
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10LL
const ll MOD = 998244353;
using namespace std;

int n;

bool check(ll x) {
    if (x - x / 3LL - x / 5LL + x / 15LL < n)
        return false;
    else
        return true;
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

void Solve() {
    cin >> n;
    cout << first_true(0, lINF) << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) Solve();
    return 0;
}