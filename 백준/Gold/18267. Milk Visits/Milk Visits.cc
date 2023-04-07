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

vector<int> g[100001];

void Solve() {
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    string str;
    cin >> str;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[--a].push_back(--b);
        g[b].push_back(a);
    }
    vector<int> check(n + 1, -1);
    vector<char> cc(n + 1);
    for (int i = 0; i < n; i++) {
        if (check[i] == -1) {
            cnt++;
            check[i] = cnt;
            cc[cnt] = str[i];
            queue<int> bfsQ;
            bfsQ.push(i);
            while (!bfsQ.empty()) {
                int now = bfsQ.front();
                bfsQ.pop();
                for (int next : g[now]) {
                    if (check[next] == -1 && str[now] == str[next]) {
                        check[next] = check[now];
                        bfsQ.push(next);
                    }
                }
            }
        }
    }
    string ans;
    for (int i = 0; i < m; i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        a--;
        b--;
        if (cc[check[a]] == c || cc[check[b]] == c) {
            ans += '1';
        } else {
            if (check[a] != check[b])
                ans += '1';
            else
                ans += '0';
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cout << fixed;
    cout.precision(6);
    while (t--) Solve();
    return 0;
}
