#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

vector<pair<ll, ll>> g[10001], g2[10001];

void Solve() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<int> inDegree(n + 1, 0), inDegree2(n+1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        inDegree[b]++;
        g[a].push_back({ c, b });
        inDegree2[a]++;
        g2[b].push_back({ c, a });
    }
    int start, dest;
    cin >> start >> dest;
    vector<ll> check(n + 1, 0);
    queue<int> bfsQ;
    bfsQ.push(start);
    while (!bfsQ.empty()) {
        int now = bfsQ.front();
        bfsQ.pop();
        for (auto next : g[now]) {
            inDegree[next.second]--;
            if (inDegree[next.second] == 0) {
                bfsQ.push(next.second);
            }
            if (check[next.second] < check[now] + next.first) {
                check[next.second] = check[now] + next.first;
            }
        }
    }
    cout << check[dest]<<'\n';
    bfsQ.push(dest);
    int ans = 0;
    vector<bool> check2(n + 1, false);
    check2[dest] = true;
    while (!bfsQ.empty()) {
        int now = bfsQ.front();
        bfsQ.pop();
        for (auto next : g2[now]) {
            if (check2[now]&&check[now] == check[next.second] + next.first) {
                ans++;
                check2[next.second] = true;
            }
            inDegree2[next.second]--;
            if (inDegree2[next.second] == 0) {
                bfsQ.push(next.second);
            }
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
// 1. "추론"(그 증명)
// 2. 알고리즘 "처음"부터 풀이과정 직접 전개, cutting
// 3. "구현"