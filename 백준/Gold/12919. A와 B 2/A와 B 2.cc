#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;
    map<string, int> check;
    queue<string> bfsQ;
    bfsQ.push(t);
    check[t] = 1;
    while (!bfsQ.empty()) {
        string now = bfsQ.front();
        bfsQ.pop();
        if (now.size() < s.size()) continue;
        if (now.back() == 'A') {
            string next = now;
            next.pop_back();
            if (check.count(next) == 0) {
                bfsQ.push(next);
                check[next] = 1;
            }
        }
        if (now.front() == 'B') {
            string next = now;
            reverse(next.begin(), next.end());
            next.pop_back();
            if (check.count(next) == 0) {
                bfsQ.push(next);
                check[next] = 1;
            }
        }
    }
    if (check.count(s) != 0) {
        cout << 1 << '\n';
    } else {
        cout << 0 << '\n';
    }
}

int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while (t--) solve();
    return 0;
}
