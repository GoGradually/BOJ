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

int dp[100001][3];
int go(int index, int k) {
    if (dp[index][k] != -1) return dp[index][k];
    int &ret = dp[index][k];
    ret = 0;
    for (int j = 0; j < 3; j++) {
        if (k != 0 && j == k) continue;
        ret += go(index - 1, j);
        ret %= 9901;
    }

    return ret;
}
void solve() {
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 1;
    int n;
    cin >> n;
    cout << (go(n, 0) + go(n, 1) + go(n, 2)) % 9901 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
