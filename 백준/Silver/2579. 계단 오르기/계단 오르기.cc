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

int dp[301][2];
int arr[301];
int go(int n, int k) {
    if (n == 0) return 0;
    if (k < 0 || n < 0) return -1;
    if (dp[n][k] != -1) return dp[n][k];
    int& ret = dp[n][k];
    ret = 0;
    ret = arr[n] + max({go(n - 1, k - 1), go(n - 2, 0), go(n - 2, 1)});
    return ret;
}
void solve() {
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    dp[0][0] = 0;
    dp[0][1] = 0;
    cout << max({go(n, 0), go(n, 1)}) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
