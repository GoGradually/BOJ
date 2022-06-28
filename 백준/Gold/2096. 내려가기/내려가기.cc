#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int dp[2][5];
int mdp[2][5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int arr[5];
    for (int i = 1; i <= n; i++) {
        cin >> arr[1] >> arr[2] >> arr[3];
        for (int j = 1; j < 4; j++) {
            dp[1][j] = max({dp[0][j - 1], dp[0][j], dp[0][j + 1]}) + arr[j];
            if (j == 1) {
                mdp[1][j] = min({mdp[0][j + 1], mdp[0][j]}) + arr[j];
            }
            if (j == 3) {
                mdp[1][j] = min({mdp[0][j - 1], mdp[0][j]}) + arr[j];
            }
            if (j == 2) {
                mdp[1][j] =
                    min({mdp[0][j - 1], mdp[0][j + 1], mdp[0][j]}) + arr[j];
            }
        }
        for (int j = 1; j < 4; j++) {
            dp[0][j] = dp[1][j];
            mdp[0][j] = mdp[1][j];
        }
    }
    cout << max({dp[1][1], dp[1][2], dp[1][3]}) << ' '
         << min({mdp[1][1], mdp[1][2], mdp[1][3]}) << '\n';
    return 0;
}