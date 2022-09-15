#include <cstring>
#include <iostream>

using namespace std;

int dp[10001];
int arr[100];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    dp[0] = 1;
    for (int j = 0; j < n; j++) {
        for (int i = 1; i <= k; i++) {
            if (arr[j] <= i) dp[i] += dp[i - arr[j]];
        }
    }
    cout << dp[k] << '\n';
    return 0;
}