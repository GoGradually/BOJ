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

int dp[100001][2];
int arr[100001][2];
int go(int n, int k) {
    if (k < 0 || n < 0) return 0;
    if (dp[n][k] != -1) return dp[n][k];
    int& ret = dp[n][k];
    ret = 0;
    ret = arr[n][k] + max({go(n - 2, 1 - k), go(n - 2, k), go(n - 1, 1 - k)});
    return ret;
}
void solve() {
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < n; i++) {
            cin >> arr[i][j];
        }
    }
    dp[0][0] = arr[0][0];
    dp[0][1] = arr[0][1];
    cout << max({go(n - 1, 0), go(n - 1, 1)}) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
