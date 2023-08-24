#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;
void Solve() {
    int n, m;
    cin>>n>>m;
    vector<vector<ll>> psum(n+1, vector<ll>(m+1)),arr(n, vector<ll>(m));
    for (int i = 0; i<n; i++) {
        string str;
        cin>>str;
        for (int j = 0; j<m; j++) {
            arr[i][j] = str[j] - '0';
            psum[i+1][j+1] += psum[i+1][j] + psum[i][j+1] + arr[i][j] - psum[i][j];
        }
    }
    int left = 0, right = 1000;
    auto check = [&] (int x){
        for (int i = 0; i+x <= n; i++) {
            for (int j = 0; j+x <= m; j++) {
                if(psum[i+x][j+x] - psum[i][j+x] - psum[i+x][j] + psum[i][j] == x*x){
                    return true;
                }
            }
        }
        return false;
    };
    while(left<=right){
        int mid = (left + right) / 2;
        if(check(mid)){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    cout<<(left - 1)*(left-1)<<'\n';
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
