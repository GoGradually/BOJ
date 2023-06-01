#include <bits/stdc++.h>
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
#define MOD 1000000007LL;
/*
#include "atcoder/modint.hpp"
using mint = atcoder::modint998244353;
*/

using namespace std;

void Solve() {
    int n, d;
    cin >> n >> d;
    map<pair<int, int>, int> check[2];
    multiset<pair<int, int>> ms[2];
    queue<pair<pair<int, int>, int>> bfsQ;
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ms[0].insert({b, a});
        if (b == 0) {
            bfsQ.push({{b, a}, 0});
            check[0][{b, a}] = 1;
        }
        ans.push_back({b, a});
    }
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ms[1].insert({a, b});
        if (a == 0) {
            bfsQ.push({{a, b}, 1});
            check[1][{a, b}] = 1;
        }
    }
    while (!bfsQ.empty()) {
        auto now = bfsQ.front().first;
        int nowPos = bfsQ.front().second;
        int A, B;
        tie(A, B) = now;
        bfsQ.pop();
        int nextPos = 1 - nowPos;
        auto start = ms[nextPos].lower_bound({B - d, 0});
        auto end = ms[nextPos].lower_bound({B, INF});
        for (auto it = start; it != end; it++) {
            pair<int, int> next = *it;
            if (check[nextPos][{next}] == 0) {
                check[nextPos][{next}] = check[nowPos][{now}] + 1;
                bfsQ.push({next, nextPos});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (check[0][ans[i]] == 0) {
            cout << -1 << '\n';
        } else {
            cout << check[0][ans[i]] << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--) Solve();
    return 0;
}
