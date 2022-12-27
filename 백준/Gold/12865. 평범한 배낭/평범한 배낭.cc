#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define MOD 1000000000LL
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;

int d[101][100001];
void solve() {
    int n, k;
    cin>>n>>k;
    vector<pair<int, int>> tray(n);
    for (int i = 0; i<n; i++) {
        int a, b;
        cin>>a>>b;
        tray[i] = make_pair(a, b);
    }
    d[0][tray[0].first] = tray[0].second;
    for (int i = 1; i<n; i++) {
        for (int j = 0; j<=k; j++) {
            if( j - tray[i].first >= 0) {
                d[i][j] = max(d[i-1][j], d[i-1][j-tray[i].first] + tray[i].second);
            }
            else d[i][j] = d[i-1][j];
        }
    }
    int ans = 0;
    for (int i = 0; i<=k; i++) {
        ans = max(ans, d[n-1][i]);
    }
    cout<<ans<<'\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
