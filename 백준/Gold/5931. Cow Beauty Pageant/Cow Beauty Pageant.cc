#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
vector<int> g[251];
void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<vector<int>> check(n, vector<int>(m, 0));
    vector<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (check[i][j] == 0) {
                check[i][j] = 1;
                if (arr[i][j] == 'X') {
                    s.push_back({i, j});
                    queue<pair<int, int>> bfsQ;
                    bfsQ.push({i, j});
                    while (!bfsQ.empty()) {
                        int x = bfsQ.front().first;
                        int y = bfsQ.front().second;
                        bfsQ.pop();
                        for (int k = 0; k < 4; k++) {
                            int p = x + dx[k], q = y + dy[k];
                            if (p >= 0 && p < n && q >= 0 && q < m &&
                                check[p][q] == 0 && arr[p][q] == 'X') {
                                check[p][q] = 1;
                                bfsQ.push({p, q});
                            }
                        }
                    }
                }
            }
        }
    }
    vector<vector<int>> dist(n, vector<int>(m, -1));
    deque<pair<int, int>> dq;
    dq.push_back(s[0]);
    dist[s[0].first][s[0].second] = 0;
    while (!dq.empty()) {
        int x = dq.front().first;
        int y = dq.front().second;
        dq.pop_front();
        for (int k = 0; k < 4; k++) {
            int p = x + dx[k], q = y + dy[k];
            if (p >= 0 && p < n && q >= 0 && q < m && dist[p][q] == -1 &&
                arr[p][q] == 'X') {
                dist[p][q] = dist[x][y];
                dq.push_front({p, q});
            }
            if (p >= 0 && p < n && q >= 0 && q < m && dist[p][q] == -1 &&
                arr[p][q] == '.') {
                dist[p][q] = dist[x][y] + 1;
                dq.push_back({p, q});
            }
        }
    }
    cout << dist[s[1].first][s[1].second] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
