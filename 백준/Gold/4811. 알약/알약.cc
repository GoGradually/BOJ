#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

void Solve() {
    while(true){
        int n;
        cin >> n;
        if(n==0) break;
        vector<vector<vector<ll>>> dp(n*2+1, vector<vector<ll>> (n*2+1, vector<ll>(2*n+1)));
        dp[n*2][n][0] = 1;
        for (int i = n*2; i>=1; i--) {
            for (int j = n*2; j>=0; j--) {
                for (int k = n*2; k>=0; k--) {
                    if(j>0)dp[i-1][j-1][k+1] += dp[i][j][k];
                    if(k>0)dp[i-1][j][k-1] += dp[i][j][k];
                }
            }
        }
        cout<<dp[0][0][0]<<'\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
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
