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
int check[251][251];

void Solve() {
    int n, b;
    cin >> n >> b;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<pair<int, int>> boots(b);
    for (int i = 0; i < b; i++) {
        cin >> boots[i].first >> boots[i].second;
    }
    check[0][0] = 1;
    queue<pair<int, int>> bfsQ;
    bfsQ.push({0, 0});
    while (!bfsQ.empty()) {
        int nowPos = bfsQ.front().first;
        int nowBoots = bfsQ.front().second;
        bfsQ.pop();
        if(nowBoots+1 < b && check[nowPos][nowBoots+1] == 0){
            check[nowPos][nowBoots + 1] = 1;
            bfsQ.push({nowPos, nowBoots + 1});
        }
        if (boots[nowBoots].first < arr[nowPos]) continue;
        for (int i = min(n - 1, nowPos + boots[nowBoots].second); i > nowPos;
             i--) {
            if (arr[i] <= boots[nowBoots].first && check[i][nowBoots] == 0) {
                bfsQ.push({i, nowBoots});
                check[i][nowBoots] = 1;
            }
        }
    }
    for (int i = 0; i < b; i++) {
        if (check[n - 1][i] == 1) {
            cout << i << '\n';
            break;
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
