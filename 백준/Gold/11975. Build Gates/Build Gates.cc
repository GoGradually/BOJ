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
    cin >> n;
    vector<vector<int>> check(4006, vector<int>(4006));
    string str;
    cin >> str;
    int startX = 2002, startY = 2002;
    check[startX][startY] = 1;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'N') {
            startY++;
            check[startX][startY] = 1;
            startY++;
        } else if (str[i] == 'S') {
            startY--;
            check[startX][startY] = 1;
            startY--;
        } else if (str[i] == 'W') {
            startX--;
            check[startX][startY] = 1;
            startX--;
        } else {
            startX++;
            check[startX][startY] = 1;
            startX++;
        }
        check[startX][startY] = 1;
    }

    int cnt = 0;
    for (int i = 0; i < 4006; i++) {
        for (int j = 0; j < 4006; j++) {
            if (check[i][j] == 0) {
                queue<pair<int, int>> bfsQ;
                bfsQ.push({i, j});
                check[i][j] = 1;
                cnt++;
                while (!bfsQ.empty()) {
                    int x = bfsQ.front().first;
                    int y = bfsQ.front().second;
                    bfsQ.pop();
                    for (int k = 0; k < 4; k++) {
                        int p = x + dx[k], q = y + dy[k];
                        if (p >= 0 && p < 4006 && q >= 0 && q < 4006 &&
                            check[p][q] == 0) {
                            bfsQ.push({p, q});
                            check[p][q] = 1;
                        }
                    }
                }
            }
        }
    }

    cout << cnt - 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) Solve();
    return 0;
}
