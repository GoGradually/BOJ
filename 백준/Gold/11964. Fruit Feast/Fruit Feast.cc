#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

void Solve() {
    int t, a, b;
    cin >> t>>a>>b;
    vector<vector<int>> check(t + 1, vector<int>(2));
    check[0][0] = 1;
    queue<pair<int, int>> bfsQ;
    bfsQ.push({0, 0});
    while (!bfsQ.empty()) {
        int now = bfsQ.front().first;
        int tag = bfsQ.front().second;
        bfsQ.pop();
        if (tag == 0 && check[now / 2][1] == 0) {
            check[now / 2][1] = 1;
            bfsQ.push({ now / 2 , 1});
        }
        if (now + a <= t && check[now + a][tag] == 0) {
            check[now + a][tag] = 1;
            bfsQ.push({ now + a , tag});
        }
        if (now + b <= t && check[now + b][tag] == 0) {
            check[now + b][tag] = 1;
            bfsQ.push({ now + b, tag});
        }
    }
    for (int i = t; i >= 0; i--)
    {
        if (check[i][0] == 1||check[i][1] == 1) {
            cout << i << '\n';
            break;
        }
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
// 알고리즘의 작동방식 "완전히" 이해하려 노력하기
// 수행 목표
// 1. "추론"(greedP, 증명으로 아이디어)
// 2. 알고리즘 "처음"부터 풀이과정 직접 전개, cutting
// 3. "구현"