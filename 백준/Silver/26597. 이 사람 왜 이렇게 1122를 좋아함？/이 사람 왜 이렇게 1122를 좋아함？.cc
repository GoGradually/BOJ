#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

void Solve() {
    int n;
    cin >> n;
    ll maxU = -1000000000000000000;
    ll minD = 1000000000000000000;
    vector<pair<ll, char>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    ll ans = -lINF;
    int ansInd = -1;
    for (int i = 0; i < n; i++) {
        ll t = arr[i].first;
        if (arr[i].second == '^') {
            if (t >= minD) {
                cout << "Paradox!\n";
                cout << i + 1 << '\n';
                return;
            }
            maxU = max(maxU, t + 1);
        }
        if (arr[i].second == 'v') {
            if (t <= maxU) {
                cout << "Paradox!\n";
                cout << i + 1 << '\n';
                return;
            }
            minD = min(minD, t - 1);
        }
        if (ans == -lINF && maxU == minD) {
            ans = maxU;
            ansInd = i + 1;
        }
    }
    if (ansInd != -1 && ans != -lINF) {
        cout << "I got it!\n";
        cout << ansInd << '\n';
        return;
    }
    else cout << "Hmm...\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--) Solve();
    return 0;
}

/*
take notes.
맵으로 돌기?

*/

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
