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

vector<int> g[200001];

queue<int> Q;
int want[100001];
ll val[100001];
int check[100001];
int n;

void dfs(int x) {
    Q.push(x);
    if (check[x] != 0) return;
    check[x] = 1;
    dfs(want[x]);
}

void Solve() {
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> want[i] >> val[i];
        want[i]--;
        ans += val[i];
    }
    for (int i = 0; i < n; i++) {
        if (check[i] == 0) {
            dfs(i);
            bool ok = false;
            ll MIN = lINF;
            while (!Q.empty()) {
                if (ok) {
                    MIN = min(MIN, val[Q.front()]);
                }
                if (Q.front() == Q.back()) ok = true;
                Q.pop();
            }
            if (MIN != lINF) ans -= MIN;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) Solve();
    return 0;
}
