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
vector<pair<int, pair<ll, ll>>> g[10];
ll dfs(int now, int past) {
    ll ret = 1;
    for (int i = 0; i < g[now].size(); i++)
    {
        if (g[now][i].first == past) continue;
        ll next, p, q;
        next = g[now][i].first;
        p = g[now][i].second.first;
        q = g[now][i].second.second;
        ll val = dfs(next, now);
        ret *= p * val;
    }
    return ret;
}
void dfs_(int now, int past) {
    for (int i = 0; i < g[now].size(); i++)
    {
        if (g[now][i].first == past) continue;
        ll next, p, q;
        next = g[now][i].first;
        p = g[now][i].second.first;
        q = g[now][i].second.second;
        arr[next] = arr[now] * q / p;
        dfs_(next, now);
    }
}
ll gcd(ll a, ll b) {
    if (a < b)swap(a, b);
    if (b == 0)return a;
    return gcd(b, a % b);
}
void Solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n-1; i++)
    {
        int a, b, p, q;
        cin >> a >> b >> p >> q;
        g[a].push_back({ b, {p, q} });
        g[b].push_back({ a, {q, p} });
    }
    arr[0] = dfs(0, -1);
    dfs_(0, -1);
    ll GCD = arr[0];
    for (int i = 1; i < n; i++)
    {
        GCD = gcd(GCD, arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]/GCD << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--) Solve();
    return 0;
}