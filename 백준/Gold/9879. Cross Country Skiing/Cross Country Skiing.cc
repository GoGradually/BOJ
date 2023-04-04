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
int arr[501][501];
int n, m;

bool Check(int mid) {
    bool check[501][501];
    memset(check, false, sizeof(check));
    queue<pair<int, int>> bfsQ;
    bfsQ.push(waypoint[0]);
    check[waypoint[0].first][waypoint[0].second] = true;
    while (!bfsQ.empty()) {
        int x, y;
        tie(x, y) = bfsQ.front();
        bfsQ.pop();
        for (int k = 0; k < 4; k++) {
            int p = x + dx[k], q = y + dy[k];
            if (p >= 0 && p < n && q >= 0 && q < m) {
                if (abs(arr[p][q] - arr[x][y]) <= mid && !check[p][q]) {
                    bfsQ.push({p, q});
                    check[p][q] = true;
                }
            }
        }
    }
    for (int i = 0; i < waypoint.size(); i++) {
        if (!check[waypoint[i].first][waypoint[i].second]) return false;
    }
    return true;
}

int First_true(int lo, int hi) {
    hi++;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (Check(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

void Solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int t;
            cin >> t;
            if (t == 1) waypoint.push_back({i, j});
        }
    }
    cout << First_true(0, 1e9) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) Solve();
    return 0;
}
