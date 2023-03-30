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

ll dist[1001][1001];
int n;

ll calDist(pair<int, int> p1, pair<int, int> p2) {
    return (p1.first - p2.first) * (p1.first - p2.first) +
           (p1.second - p2.second) * (p1.second - p2.second);
}

bool check(ll x) {
    int check[1001];
    memset(check, -1, sizeof(check));
    check[0] = 1;
    queue<int> bfsQ;
    bfsQ.push(0);
    while (!bfsQ.empty()) {
        int now = bfsQ.front();
        bfsQ.pop();
        for (int k = 0; k < n; k++) {
            if (now == k) continue;
            if (check[k] == -1 && dist[now][k] <= x) {
                check[k] = 1;
                bfsQ.push(k);
            }
        }
    }
    bool ok = true;
    for (int j = 0; j < n; j++) {
        if (check[j] == -1) ok = false;
    }
    if (ok) return true;

    return false;
}

ll first_true(ll lo, ll hi) {
    hi++;
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}
void solve() {
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = dist[j][i] = calDist(arr[i], arr[j]);
        }
    }
    cout << first_true(0, 1300000000LL) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
