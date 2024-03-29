#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
void Solve() {
    int n;
    cin>>n;
    vector<vector<int>> arr(n, vector<int>(n));
    vector<tuple<int, int, int>> pool;
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            cin>>arr[i][j];
            pool.push_back({arr[i][j], i, j});
        }
    }
    sort(pool.begin(), pool.end());
    vector<vector<int>> dp(n, vector<int>(n, 1));
    int ans = 1;
    for (int i =0; i<pool.size(); i++) {
        int a, b, c;
        tie(c, a, b) = pool[i];
        for (int k = 0; k<4; k++) {
            int p = a+dx[k], q = b+dy[k];
            if(p>=0&&p<n &&q>=0&&q<n){
                if(arr[a][b] < arr[p][q]){
                    dp[p][q] = max(dp[p][q], dp[a][b]+1);
                    ans = max(ans, dp[p][q]);
                }
            }
        }
    }
    cout<<ans<<'\n';
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
