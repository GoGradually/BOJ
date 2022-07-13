#include <bits/stdc++.h>
using namespace std;
int dp[20][21][21];
int MOVE[20];
int mCnt;
int go(int index, int x, int y) {
    if (index == mCnt) return 0;
    if (dp[index][x][y] != -1) return dp[index][x][y];
    return dp[index][x][y] =
               min(abs(x - MOVE[index]) + go(index + 1, MOVE[index], y),
                   abs(y - MOVE[index]) + go(index + 1, x, MOVE[index]));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t1, t2;
    pair<int, int> blank;
    cin >> n >> t1 >> t2;
    cin >> mCnt;
    for (int i = 0; i < mCnt; i++) {
        cin >> MOVE[i];
    }
    memset(dp, -1, sizeof(dp));
    int ans = go(0, t1, t2);
    cout << ans << '\n';
    return 0;
}