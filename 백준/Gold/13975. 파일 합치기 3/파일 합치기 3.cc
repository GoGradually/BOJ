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
#define MOD 998244353LL
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;
void solve() {
    int n;
    cin >> n;
    ll ans = 0;
    priority_queue<ll> pq;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        pq.push(-t);
    }
    while (pq.size() > 1) {
        ll f = -pq.top();
        pq.pop();
        ll s = -pq.top();
        pq.pop();
        pq.push(-s - f);
        ans += s + f;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
