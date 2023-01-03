#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define MOD 1000000000LL
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;

string code = ".RGBPY";
int check[12][6];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void solve() {
    string arr[12];
    for (int i = 0; i < 12; i++) {
        cin >> arr[i];
    }
    int ret = 0;
    while (true) {
        bool serial = false;
        memset(check, 0, sizeof(check));
        for (int i = 11; i >= 0; i--) {
            for (int j = 0; j < 6; j++) {
                if (arr[i][j] != '.' && check[i][j] == 0) {
                    check[i][j] = 1;
                    int cnt = 1;
                    queue<pair<int, int>> bfsQ;
                    bfsQ.push(make_pair(i, j));
                    bool ok = false;
                    while (!bfsQ.empty()) {
                        int x = bfsQ.front().first, y = bfsQ.front().second;
                        bfsQ.pop();
                        if (check[x][y] > 3) {
                            ok = true;
                            break;
                        }
                        for (int k = 0; k < 4; k++) {
                            int p = x + dx[k], q = y + dy[k];
                            if (p < 12 && p >= 0 && q < 6 && q >= 0 &&
                                check[p][q] == 0 && arr[p][q] == arr[x][y]) {
                                check[p][q] = ++cnt;
                                bfsQ.push(make_pair(p, q));
                            }
                        }
                    }
                    bfsQ = queue<pair<int, int>>();
                    bfsQ.push({i, j});
                    if (ok) {
                        serial = true;
                        int check2[12][6] = {};
                        char code2 = arr[i][j];
                        memset(check2, 0, sizeof(check2));
                        while (!bfsQ.empty()) {
                            int x = bfsQ.front().first, y = bfsQ.front().second;
                            bfsQ.pop();
                            arr[x][y] = '.';
                            for (int k = 0; k < 4; k++) {
                                int p = x + dx[k], q = y + dy[k];
                                if (p < 12 && p >= 0 && q < 6 && q >= 0 &&
                                    check2[p][q] == 0 && arr[p][q] == code2) {
                                    check2[p][q] = check2[x][y] + 1;
                                    bfsQ.push({p, q});
                                }
                            }
                        }
                    }
                }
            }
        }
        if (!serial) break;
        ret++;
        for (int i = 11; i >= 0; i--) {
            for (int j = 0; j < 6; j++) {
                int x = i + 1, y = j;
                while (x < 12 && arr[x][y] == '.') x++;
                x--;
                swap(arr[i][j], arr[x][y]);
            }
        }
    }
    cout << ret << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
