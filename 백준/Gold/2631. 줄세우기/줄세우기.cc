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

int dp[1001];
int arr[1001];
int go(int index) {
    if (dp[index] != -1) return dp[index];
    int &ret = dp[index];
    ret = 0;
    for (int i = 0; i < index; i++) {
        if (arr[index] > arr[i]) {
            ret = max(ret, go(i));
        }
    }
    ret++;
    return ret;
}
void solve() {
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = ans < go(i) ? go(i) : ans;
    }

    cout << n - ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}