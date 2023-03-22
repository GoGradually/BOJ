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

void solve() {
    int n;
    cin >> n;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                   greater<>>
        arriving, waiting;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arriving.push({a, i, b});
    }
    int ans = 0;
    int nowTime = get<0>(arriving.top()) + get<2>(arriving.top());
    arriving.pop();
    while (!arriving.empty() || !waiting.empty()) {
        while (!arriving.empty() && nowTime >= get<0>(arriving.top())) {
            int i, a, b;
            tie(a, i, b) = arriving.top();
            arriving.pop();
            waiting.push({i, a, b});
        }
        int i, a, b;
        if (!waiting.empty()) {
            tie(i, a, b) = waiting.top();
            waiting.pop();
        } else {
            tie(a, i, b) = arriving.top();
            nowTime = a;
            arriving.pop();
        }
        ans = max(ans, nowTime - a);
        nowTime += b;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
