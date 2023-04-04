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
#define MOD 1000000007
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

vector<pair<int, int>> waypoint;
int n, m;
vector<pair<int, int>> arr[101][101];
void Solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        arr[--x][--y].push_back({--a, --b});
    }
    vector<vector<int>> on(n, vector<int>(n));
    vector<vector<int>> check(n, vector<int>(n));
    queue<pair<int, int>> bfsQ;
    bfsQ.push({0, 0});

    check[0][0] = 1;
    on[0][0] = 1;
    for (int i = 0; i < arr[0][0].size(); i++) {
        int x = arr[0][0][i].first;
        int y = arr[0][0][i].second;
        on[x][y] = 1;
    }
    while (!bfsQ.empty()) {
        int x = bfsQ.front().first;
        int y = bfsQ.front().second;
        bfsQ.pop();
        for (int k = 0; k < 4; k++) {
            int p = x + dx[k], q = y + dy[k];
            if (p >= 0 && p < n && q >= 0 && q < n && on[p][q] == 1 &&
                check[p][q] == 0) {
                bfsQ.push({p, q});
                check[p][q] = 1;
                for (int i = 0; i < arr[p][q].size(); i++) {
                    int u = arr[p][q][i].first;
                    int v = arr[p][q][i].second;
                    on[u][v] = 1;
                    for (int l = 0; l < 4; l++) {
                        int w = u + dx[l], z = v + dy[l];
                        if (w >= 0 && w < n && z >= 0 && z < n &&
                            check[w][z] == 1 && on[w][z] == 1) {
                            bfsQ.push({w, z});
                            break;
                        }
                    }
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cnt += on[i][j];
        }
    }
    cout << cnt << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) Solve();
    return 0;
}
