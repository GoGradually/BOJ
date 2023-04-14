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

vector<pair<int, int>> g[100001];
int n, m;
int arr[100001];

bool check(ll x) {
    vector<int> check(n, -1);
    for (int i = 0; i < n; i++) {
        if (check[i] == -1) {
            set<int> s;
            if (s.find(arr[i]) != s.end())
                s.erase(arr[i]);
            else
                s.insert(arr[i]);
            if (s.find(i) != s.end())
                s.erase(i);
            else
                s.insert(i);
            queue<int> bfsQ;
            bfsQ.push(i);
            check[i] = 1;
            while (!bfsQ.empty()) {
                int now = bfsQ.front();
                bfsQ.pop();
                for (auto &&next : g[now]) {
                    if (next.first >= x) {
                        if (check[next.second] == -1) {
                            check[next.second] = 1;
                            bfsQ.push(next.second);
                            if (s.find(arr[next.second]) != s.end())
                                s.erase(arr[next.second]);
                            else
                                s.insert(arr[next.second]);
                            if (s.find(next.second) != s.end())
                                s.erase(next.second);
                            else
                                s.insert(next.second);
                        }
                    }
                }
            }
            if (s.size() != 0) return false;
        }
    }
    return true;
}

ll last_true(ll lo, ll hi) {
    lo--;
    while (lo < hi) {
        ll mid = lo + (hi - lo + 1) / 2;
        if (check(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    return lo;
}

void Solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i]--;
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[--a].push_back({c, --b});
        g[b].push_back({c, a});
    }

    ll ans = last_true(0, 1e9+1);
    if (ans == 1e9+1)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--) Solve();
    return 0;
}
