#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;

int squ(int a) { return a * a; }

void solve() {
    int x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    int dSqu = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
    if (dSqu == 0 && r1 == r2)
        cout << -1 << '\n';
    else if (dSqu > squ(r1 + r2))
        cout << 0 << '\n';
    else if (dSqu == squ(r1 + r2))
        cout << 1 << '\n';
    else if (dSqu < squ(r1 + r2) && dSqu > squ(r2 - r1))
        cout << 2 << '\n';
    else if (dSqu == squ(r2 - r1))
        cout << 1 << '\n';
    else if (dSqu < squ(r2 - r1))
        cout << 0 << '\n';
}

int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
