#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int dp[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    int n;
    cin >> n;
    vector<pair<int, int>> coin(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        coin[i] = {a, b};
    }
    dp[0] = 1;
    sort(coin.begin(), coin.end(), greater<>());
    for (int i = 0; i < n; i++)
    {
        int coinVal, coinCnt;
        tie(coinVal, coinCnt) = coin[i];
        for (int j = T; j>=0; j--)
        {
            for (int k = 1; k <= coinCnt&&j-coinVal*k>=0; k++)
            {
                dp[j] += dp[j - k * coinVal];
            }
        }
    }
    cout << dp[T];
    return 0;
}