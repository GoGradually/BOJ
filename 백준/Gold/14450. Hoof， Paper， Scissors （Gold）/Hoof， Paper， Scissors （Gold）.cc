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
#define MOD 998244353LL
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10

using namespace std;
int d[100001][21][3];
void Solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        char t;
        cin >> t;
        if (t == 'P') arr[i] = 0;
        if (t == 'H') arr[i] = 1;
        if (t == 'S') arr[i] = 2;
    }
    d[0][0][arr[0]] = 1;
    for (int i = 1; i < n; i++) {
        d[i][0][0] = d[i - 1][0][0] + (0 == arr[i]);
        d[i][0][1] = d[i - 1][0][1] + (1 == arr[i]);
        d[i][0][2] = d[i - 1][0][2] + (2 == arr[i]);
        for (int j = 1; j <= k; j++) {
            d[i][j][0] =
                max({d[i - 1][j][0], d[i - 1][j - 1][1], d[i - 1][j - 1][2]}) +
                (0 == arr[i]);
            d[i][j][1] =
                max({d[i - 1][j][1], d[i - 1][j - 1][0], d[i - 1][j - 1][2]}) +
                (1 == arr[i]);
            d[i][j][2] =
                max({d[i - 1][j][2], d[i - 1][j - 1][1], d[i - 1][j - 1][0]}) +
                (2 == arr[i]);
        }
    }
    int ans = max({d[n - 1][k][0], d[n - 1][k][1], d[n - 1][k][2]});
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--) Solve();
    return 0;
}
