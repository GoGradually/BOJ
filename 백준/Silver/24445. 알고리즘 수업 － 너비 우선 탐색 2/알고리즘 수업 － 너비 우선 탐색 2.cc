#include <bits/stdc++.h>
using namespace std;

int n, m, r;
vector<int> g[100001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> r;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end(), greater<>());
    }
    vector<int> check(n + 1, 0);
    check[r] = 1;
    queue<int> bfsQ;
    bfsQ.push(r);
    int temp = 1;
    while (!bfsQ.empty()) {
        int now = bfsQ.front();
        bfsQ.pop();
        for (auto &&i : g[now]) {
            if (check[i] == 0) {
                check[i] = ++temp;
                bfsQ.push(i);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << check[i]<< '\n';
    }

    return 0;
}