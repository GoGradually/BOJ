#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> check(n + 1, -1);
    check[n] = 0;
    queue<int> bfsq;
    bfsq.push(n);
    while (!bfsq.empty()) {
        int now = bfsq.front();
        bfsq.pop();
        if (now % 2 == 0 && check[now / 2] == -1) {
            bfsq.push(now / 2);
            check[now / 2] = check[now] + 1;
        }
        if (now % 3 == 0 && check[now / 3] == -1) {
            bfsq.push(now / 3);
            check[now / 3] = check[now] + 1;
        }
        if (check[now - 1] == -1) {
            bfsq.push(now - 1);
            check[now - 1] = check[now] + 1;
        }
    }
    cout << check[1] << '\n';
}

int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while (t--) solve();
    return 0;
}
