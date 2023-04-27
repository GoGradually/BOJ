#include <algorithm>
#include <array>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define MOD 998244353LL
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int arr[101][101];
ll check[101][101][3];
void Solve() {
    int n, t;
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    priority_queue<tuple<ll, int, int, int>> pq;
    memset(check, 0x3f, sizeof(check));
    check[0][0][0] = 0;
    pq.push({0, 0, 0, 0});
    while (!pq.empty()) {
        int nTime, x, y, cnt;
        tie(nTime, x, y, cnt) = pq.top();
        nTime *= -1;
        pq.pop();
        if (nTime < check[x][y][cnt]) continue;
        for (int k = 0; k < 4; k++) {
            int p = x + dx[k], q = y + dy[k];
            int nextCnt = (cnt + 1) % 3;
            int nextTime = nTime + t;
            if (p < 0 || p >= n || q < 0 || q >= n) continue;
            if (nextCnt == 0) {
                nextTime += arr[p][q];
            }
            if (nextTime < check[p][q][nextCnt]) {
                pq.push({-nextTime, p, q, nextCnt});
                check[p][q][nextCnt] = nextTime;
            }
        }
    }
    cout << min({check[n - 1][n - 1][0], check[n - 1][n - 1][2],
                 check[n - 1][n - 1][1]})
         << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--) Solve();
    return 0;
}
