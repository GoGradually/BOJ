#include <bits/stdc++.h>
#define MOD 1000000007LL
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;

int dp[1000001][2];
int arr[10001];
vector<int> g[1000001];
int go(int index, int ok, int start) {
    if (dp[index][ok] != -1) return dp[index][ok];
    if (index != start && g[index].size() == 1) return dp[index][ok] = ok*arr[index];
    int ret = ok*arr[index];
    for (int i = 0; i < g[index].size(); i++) {
        int next = g[index][i];
        if (next == start) continue;
        if (ok == 1)
            ret += go(next, 0, index);
        else
            ret += max(go(next, ok, index), go(next, 1 - ok, index));
    }
    return dp[index][ok] = ret;
}

void solve() {
    ll n;
    cin >> n;
    for(int i = 1; i<=n; i++){
        cin>>arr[i];
    }
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int start = 1;
    cout << max(go(start, 0, start), go(start, 1, start)) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
