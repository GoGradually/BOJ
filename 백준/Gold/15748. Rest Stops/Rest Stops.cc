#include <bits/stdc++.h>
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
#define MOD 1000000007LL;
/*
#include "atcoder/modint.hpp"
using mint = atcoder::modint998244353;
*/

using namespace std;

void Solve() {
    int l, n, r1, r2;
    cin >> l >> n >> r1 >> r2;
    priority_queue<pair<ll, ll>> pq;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        pq.push({b, a});
    }
    ll nowPos = 0;
    ll ans = 0;
    while (!pq.empty()) {
        ll nextGrass = pq.top().first;
        ll nextPos = pq.top().second;
        pq.pop();
        if (nextPos < nowPos) continue;
        ans += (r1 - r2) * nextGrass * (nextPos - nowPos);
        nowPos = nextPos;
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
