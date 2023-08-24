#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000009LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;
ll dp[1001][1001][3];
void Solve() {
    int n, m;
    cin >> n >> m;
    cout << (dp[m][n][0] + dp[m][n][1] + dp[m][n][2]) % MOD << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    int m = 1000, n = 1000;
    dp[1][3][2] = 1;
    dp[1][2][1] = 1;
    dp[1][1][0] = 1;

    for (int i = 2; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k < 3; k++) {
                int now = k + 1;
                if (j < now) continue;
                dp[i][j][k] += dp[i - 1][j - now][0];
                dp[i][j][k] %= MOD;
                dp[i][j][k] += dp[i - 1][j - now][1];
                dp[i][j][k] %= MOD;
                dp[i][j][k] += dp[i - 1][j - now][2];
                dp[i][j][k] %= MOD;
            }
        }
    }
    while (T--) Solve();
    return 0;
}

/*
찾아야 할 것들
*int 오버플로우, out of bounds
*특수한 경우(n=1?)
*아무것도 하지 않는 대신 무언가를 수행하기. 체계적인 상태를 유지.
*적어두기
*한가지 접근 방식에 얽메이지 말기
*/
// 문제의 "맥" 잡고있기, 알고리즘의 작동방식 "완전히" 이해하려 노력하기
// "처음"(ex: n=1) 부터 직접 경우의 수 전개 (수식/머릿속 시각화) +
// cutting + 그리디한 "추론"(증명 idea) -> 자료구조/알고리즘의 필요성 느끼기
