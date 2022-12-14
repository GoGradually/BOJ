#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define MOD 1000000000LL
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;

void solve() {
    string str;
    cin >> str;
    vector<ll> dp(42, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 1; i < str.size(); i++) {
        int ind = i + 1;
        int digit1 = str[i] - '0';
        if(digit1!=0) dp[ind] += dp[ind - 1];
        int digit2 = str[i - 1] - '0';
        int num = digit2 * 10 + digit1;
        if (num <= 34&&num>9) dp[ind] += dp[ind - 2];
    }
    cout << dp[str.size()] << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
