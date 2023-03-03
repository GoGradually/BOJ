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

ll dp[501][501];
ll go(int n, int k) {
    if (dp[n][k] != -1) return dp[n][k];
    ll &ret = dp[n][k];
    ret = 0;
    for (int i = 0; i <= n; i++) {
        ret += go(n - i, k - 1);
        ret %= 1000000000;
    }
    return ret;
}
void solve() {
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 1;
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 0;
    }

    cout << go(n, k) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
