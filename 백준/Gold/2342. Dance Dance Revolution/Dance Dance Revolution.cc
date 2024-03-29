#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;
int cost[5][5];
void Solve() {
    vector<int> arr;
    for (int i = 1; i < 5; i++) {
        cost[0][i] = 2;
        cost[i][i] = 1;
    }
    cost[2][4] = cost[4][2] = 4;
    cost[1][3] = cost[3][1] = 4;
    cost[1][2] = cost[2][1] = 3;
    cost[2][3] = cost[3][2] = 3;
    cost[3][4] = cost[4][3] = 3;
    cost[4][1] = cost[1][4] = 3;

    while (1) {
        int temp;
        cin >> temp;
        if (temp == 0) break;
        arr.push_back(temp);
    }
    vector<vector<vector<int>>> dp(arr.size() + 1,
                                   vector<vector<int>>(5, vector<int>(5, INF)));
    dp[0][0][0] = 0;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                dp[i + 1][arr[i]][k] =
                    min(dp[i + 1][arr[i]][k], dp[i][j][k] + cost[j][arr[i]]);
                dp[i + 1][j][arr[i]] =
                    min(dp[i + 1][j][arr[i]], dp[i][j][k] + cost[k][arr[i]]);
            }
        }
    }
    int ans = INF;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            ans = min(ans, dp[arr.size()][i][j]);
        }
    }
    cout << ans << '\n';
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
// 알고리즘의 작동방식 "완전히" 이해하려 노력하기
// 수행 목표
// 1. "추론"({greedy, D&C, DP, graph}, 증명으로 아이디어)
// 2. 알고리즘 "처음"부터 풀이과정 직접 전개, cutting
// 3. "구현"