#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

vector<vector<int>> arr;
int n, m, h;
bool go(int y, int x, int start) {
    if (y == h) {
        if (x == start)
            return true;
        else
            return false;
    }
    if (x > 0 && arr[y][x - 1] == 1) {
        return go(y + 1, x - 1, start);
    } else if (x < n - 1 && arr[y][x] == 1) {
        return go(y + 1, x + 1, start);
    } else {
        return go(y + 1, x, start);
    }
}
void Solve() {
    cin >> n >> m >> h;
    arr.resize(h);
    for (int i = 0; i < h; i++) {
        arr[i].resize(n, 0);
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        arr[a][b] = 1;
    }
    int ans = 4;
    bool flag1 = true;
    for (int test = 0; test < n; test++) {
        if (!go(0, test, test)) {
            flag1 = false;
            break;
        }
    }
    if (flag1) {
        cout << 0 << '\n';
        return;
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < n - 1; j++) {
            int cnt = 0;

            if (arr[i][j] == 1) continue;
            if (j > 0 && arr[i][j - 1] == 1) continue;
            if (j < n - 1 && arr[i][j + 1] == 1) continue;
            cnt++;
            arr[i][j] = 1;

            bool flag2 = true;
            for (int test = 0; test < n; test++) {
                if (!go(0, test, test)) {
                    flag2 = false;
                    break;
                }
            }
            if (flag2) ans = min(ans, cnt);

            for (int k = 0; k < h; k++) {
                for (int l = 0; l < n - 1; l++) {
                    if (arr[k][l] == 1) continue;
                    if (l > 0 && arr[k][l - 1] == 1) continue;
                    if (l < n - 1 && arr[k][l + 1] == 1) continue;
                    cnt++;
                    arr[k][l] = 1;

                    bool flag3 = true;
                    for (int test = 0; test < n; test++) {
                        if (!go(0, test, test)) {
                            flag3 = false;
                            break;
                        }
                    }
                    if (flag3) ans = min(ans, cnt);

                    for (int p = 0; p < h; p++) {
                        for (int q = 0; q < n - 1; q++) {
                            if (arr[p][q] == 1) continue;
                            if (q > 0 && arr[p][q - 1] == 1) continue;
                            if (q < n - 1 && arr[p][q + 1] == 1) continue;
                            cnt++;
                            arr[p][q] = 1;

                            bool flag4 = true;
                            for (int test = 0; test < n; test++) {
                                if (!go(0, test, test)) {
                                    flag4 = false;
                                    break;
                                }
                            }
                            if (flag4) ans = min(ans, cnt);
                            cnt--;
                            arr[p][q] = 0;
                        }
                    }
                    cnt--;
                    arr[k][l] = 0;
                }
            }
            cnt--;
            arr[i][j] = 0;
        }
    }
    if (ans >= 4)
        cout << -1 << '\n';
    else
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
// 1. "추론"(문제 특징의 "증명"으로 아이디어){greedy, D&C, DP, graph, math}
// 2. "처음"부터 직접 경우의 수 전개(수식&도식화)
// 3. cutting | 구현(차근차근 단순화)

/*
take notes.
// 다시 보는용이 아닌
// 현재의 흐름을 가장 잘 이어갈 수 있도록 !!!

*/

// commit 시 피드백할 것 Message로 남겨두기!!