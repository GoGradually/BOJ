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

ll dp[100001];
ll go(int n) {
    if (n < 0) return 0;
    if (dp[n] != -1) return dp[n];
    ll &ret = dp[n];
    ret = go(n-2) * 3;
    for (int i = n - 4; i >= 0; i -= 2) {
        ret += 2 * go(i);
    }
    return ret;
}
void solve() {
    memset(dp, -1, sizeof(dp));
    int n;
    dp[0] = 1;
    cin >> n;
    cout << go(n) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
