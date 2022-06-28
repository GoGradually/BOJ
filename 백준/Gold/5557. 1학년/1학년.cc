#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

long long dp[101][21];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    dp[0][arr[0]] = 1;
    for (int i = 0; i < n - 1; i++) {
        for (int now = 0; now <= 20; now++) {
            if (now + arr[i+1] <= 20) {
                dp[i+1][now + arr[i+1]] += dp[i][now];
            }
            if (now - arr[i+1] >= 0) {
                dp[i + 1][now - arr[i+1]] += dp[i][now];
            }
        }
    }
    cout << dp[n-2][arr[n - 1]];

    return 0;
}