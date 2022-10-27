#include <bits/stdc++.h>
#define MOD 1000000007LL
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> check(n + 1, -1), path(n + 1, -1);
    check[n] = 0;
    path[n] = n;
    queue<int> bfsQ;
    bfsQ.push(n);
    while (!bfsQ.empty()) {
        int now = bfsQ.front();
        bfsQ.pop();
        if (now % 3 == 0 && check[now / 3] == -1) {
            bfsQ.push(now / 3);
            path[now / 3] = now;
            check[now / 3] = check[now] + 1;
        }
        if (now % 2 == 0 && check[now / 2] == -1) {
            bfsQ.push(now / 2);
            path[now / 2] = now;
            check[now / 2] = check[now] + 1;
        }
        if (now - 1 > 0 && check[now - 1] == -1) {
            bfsQ.push(now - 1);
            path[now - 1] = now;
            check[now - 1] = check[now] + 1;
        }
    }
    cout << check[1] << '\n';
    vector<int> route;
    route.push_back(1);
    int ro = 1;
    while (ro != n) {
        ro = path[ro];
        route.push_back(ro);
    }
    reverse(route.begin(), route.end());
    for (auto &&i : route) {
        cout << i << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
