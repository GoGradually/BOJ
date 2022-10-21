#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
#define MOD 998244353LL
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int go(vector<vector<int>> &arr, int n, int m) {
    vector<vector<int>> check(n, vector<int>(m, -1));
    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 2 && check[i][j] == -1) {
                int size = 1;
                queue<pair<int, int>> bfsQ;
                check[i][j] = 1;
                bfsQ.push(make_pair(i, j));
                while (!bfsQ.empty()) {
                    int x, y;
                    tie(x, y) = bfsQ.front();
                    bfsQ.pop();
                    for (int k = 0; k < 4; k++) {
                        int p = x + dx[k], q = y + dy[k];
                        if (p < n && p >= 0 && q < m && q >= 0 &&
                            check[p][q] == -1) {
                            if (arr[p][q] == 0) {
                                size = -100000000;
                            }
                            if (arr[p][q] == 2) {
                                check[p][q] = check[x][y];
                                bfsQ.push(make_pair(p, q));
                                size++;
                            }
                        }
                    }
                }
                if (0 < size) ret += size;
            }
        }
    }
    return ret;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n * m; i++) {
        if (arr[i / m][i % m] == 0) {
            arr[i / m][i % m] = 1;
            for (int j = i + 1; j < n * m; j++) {
                if (arr[j / m][j % m] == 0) {
                    arr[j / m][j % m] = 1;
                    int val = go(arr, n, m);
                    if (val > ans) ans = val;
                    arr[j / m][j % m] = 0;
                }
            }
            arr[i / m][i % m] = 0;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
