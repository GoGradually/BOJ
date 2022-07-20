#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> g[1000];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> ind(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        ind[b]++;
    }
    queue<int> Q;
    vector<int> time(n);
    for (int i = 0; i < n; i++) {
        if (ind[i] == 0) {
            Q.push(i);
            time[i] = 1;
        }
    }
    while (!Q.empty()) {
        int now = Q.front();
        Q.pop();
        for (int i = 0; i < g[now].size(); i++) {
            int next = g[now][i];
            ind[next]--;
            if (ind[next] == 0) {
                Q.push(next);
                time[next] = time[now] + 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << time[i] << ' ';
    }

    return 0;
}