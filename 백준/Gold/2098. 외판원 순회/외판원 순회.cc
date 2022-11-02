#include <bits/stdc++.h>
#define MOD 998244353LL
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;

int dp[(1 << 16)][16];
int arr[16][16];
int n;
int go(int record, int now) {
    int &ret = dp[record][now];
    if (ret != -1) return ret;
    if (record == (1 << n) - 1) {
        if (arr[now][0] != 0)
            return arr[now][0];
        else
            return INF;
    }
    ret = INF;
    for (int i = 0; i < n; i++) {
        if ((record & (1 << i)) == 0 && arr[now][i] != 0) {
            ret = min(ret, go(record | (1 << i), i) + arr[now][i]);
        }
    }
    return ret;
}
void solve() {
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    cout << go(1, 0) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
