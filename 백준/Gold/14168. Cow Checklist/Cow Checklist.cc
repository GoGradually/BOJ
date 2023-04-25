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
#define MOD 998244353LL
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10

using namespace std;

int dp[1001][1001][2];
int h, g;
vector<pair<int, int>> hols, guernsey;

int dist(pair<int, int> start, pair<int, int> end) {
    return abs(end.first - start.first) * abs(end.first - start.first) +
           abs(end.second - start.second) * abs(end.second - start.second);
}

int go(int nowH, int nowG, int pos) {
    if(nowG<0)return INF;
    if(nowH<1)return INF;
    int& ret = dp[nowH][nowG][pos];
    if (ret != -1) {
        return ret;
    }
    ret = INF;
    if (pos == 0) {
        ret =
            min(go(nowH - 1, nowG, 1 - pos) + dist(guernsey[nowG], hols[nowH]),
                go(nowH - 1, nowG, pos) + dist(hols[nowH - 1], hols[nowH]));
    } else {
        ret = min(
            go(nowH, nowG - 1, 1 - pos) + dist(hols[nowH], guernsey[nowG]),
            go(nowH, nowG - 1, pos) + dist(guernsey[nowG - 1], guernsey[nowG]));
    }
    return ret;
}

void Solve() {
    memset(dp, -1, sizeof(dp));
    cin >> h >> g;
    hols.resize(h + 1);
    guernsey.resize(g + 1);
    dp[1][0][0] = 0;
    for (int i = 1; i <= h; i++) {
        cin >> hols[i].first >> hols[i].second;
    }
    for (int i = 1; i <= g; i++) {
        cin >> guernsey[i].first >> guernsey[i].second;
    }
    for (int i = 2; i <= h; i++) {
        dp[i][0][0] = dp[i - 1][0][0] + dist(hols[i - 1], hols[i]);
    }

    cout << go(h, g, 0) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--) Solve();
    return 0;
}
