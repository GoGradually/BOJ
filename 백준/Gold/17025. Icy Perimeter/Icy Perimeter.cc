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

int arr[1001][1001];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int check[1001][1001];
void solve() {
    int n;
    cin >> n;
    vector<string> str(n);
    for (int i = 0; i < n; i++) {
        cin >> str[i];
        for (int j = 0; j < n; j++) {
            if (str[i][j] == '#') arr[i][j] = 1;
        }
    }
    int cnt = 0;
    pair<int, int> ans = {0, INF};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 1 && check[i][j] == 0) {
                queue<pair<int, int>> bfsQ;
                bfsQ.push({i, j});
                check[i][j] = ++cnt;
                int size = 1, perimeter = 0;
                while (!bfsQ.empty()) {
                    int nowX, nowY;
                    tie(nowX, nowY) = bfsQ.front();
                    bfsQ.pop();
                    for (int k = 0; k < 4; k++) {
                        int nextX = nowX + dx[k];
                        int nextY = nowY + dy[k];
                        if (nextX >= 0 && nextX < n && nextY >= 0 &&
                            nextY < n && arr[nextX][nextY] == 1) {
                            if (check[nextX][nextY] == 0) {
                                check[nextX][nextY] = cnt;
                                bfsQ.push({nextX, nextY});
                                size++;
                            }
                        } else {
                            perimeter++;
                        }
                    }
                }
                if (ans.first <= size) {
                    if (ans.first < size) {
                        ans.first = size;
                        ans.second = perimeter;
                    } else if (ans.first == size && ans.second > perimeter) {
                        ans.first = size;
                        ans.second = perimeter;
                    }
                }
            }
        }
    }
    cout << ans.first << ' ' << ans.second << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
