#include <bits/stdc++.h>
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10LL
// #define int long long
const ll MOD = 1000000007LL;

// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

int check[(1 << 15)][15][10];

void Solve() {
    int n;
    cin >> n;
    vector<string> str(n);
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = str[i][j] - '0';
        }
    }
    check[1][0][0] = 1;
    queue<tuple<int, int, int>> bfsQ;
    bfsQ.push({1, 0, 0});
    int mx = 0;
    while (!bfsQ.empty()) {
        int bit, now, nowP;
        tie(bit, now, nowP) = bfsQ.front();
        bfsQ.pop();
        for (int i = 0; i < n; i++) {
            if ((bit & (1 << i)) == 0) {
                int nextBit = bit | (1 << i);
                if (arr[now][i] >= nowP &&
                    check[nextBit][i][arr[now][i]] == 0) {
                    check[nextBit][i][arr[now][i]] = check[bit][now][nowP] + 1;
                    mx = max(check[nextBit][i][arr[now][i]], mx);
                    bfsQ.push({nextBit, i, arr[now][i]});
                }
            }
        }
    }
    cout << mx << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--) Solve();
    return 0;
}