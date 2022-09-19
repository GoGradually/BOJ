#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;
ll dp[101];

void findSmall(int n) {  // dp
    memset(dp, 0x7f, sizeof(dp));
    int arr[8] = {0, 0, 1, 7, 4, 2, 0, 8};
    dp[1] = 20000000000, dp[2] = 1, dp[3] = 7, dp[4] = 4, dp[5] = 2, dp[6] = 6, dp[7] = 8;
    for (int j = 8; j <= n; j++) {
        for (int i = 2; i < 8; i++) {
            dp[j] = min(dp[j], dp[j - i] * 10 + arr[i]);
        }
    }
    cout << dp[n] << ' ';
}
void findBig(stack<int>& big, int n) {
    if (n > 3) {
        big.push(1);
        findBig(big, n - 2);
        return;
    }
    if (n == 2) {
        big.push(1);
        return;
    }
    if (n == 3) {
        big.push(7);
        return;
    }
}

void solve() {
    int n;
    cin >> n;
    if (n == 2) {
        cout << 1 << ' ' << 1 << '\n';
        return;
    }
    if (n == 3) {
        cout << 7 << ' ' << 7 << '\n';
        return;
    }
    stack<int> big;
    findSmall(n);
    findBig(big, n);
    while (!big.empty()) {
        cout << big.top();
        big.pop();
    }
    cout << '\n';
}

int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
