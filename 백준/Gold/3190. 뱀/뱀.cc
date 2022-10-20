#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
#define MOD 998244353LL
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;

int arr[100][100];
int check[100][100];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
void solve() {
    memset(check, -1, sizeof(check));
    memset(arr, 0, sizeof(arr));
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        arr[a][b] = 1;
    }
    check[0][0] = 0;
    int dir = 0;
    int l;
    cin >> l;
    vector<pair<int, int>> plan(l);
    for (int i = 0; i < l; i++) {
        char t;
        cin >> plan[i].first >> t;
        if (t == 'L')
            plan[i].second = -1;
        else
            plan[i].second = 1;
    }
    int i = 0, t = 1;
    int x = 0, y = 0;
    int length = 1;
    for (t = 1; t < 10101; t++) {
        x += dx[dir], y += dy[dir];
        length++;
        if (x >= n || x < 0 || y >= n || y < 0 || t - check[x][y] < length) {
            break;
        }
        if (arr[x][y] == 1) {
            arr[x][y] = 0;
        }
        else {
            length--;
        }
        check[x][y] = t;
        if (i < plan.size() && plan[i].first == t) {
            dir += plan[i].second;
            dir += 4;
            dir %= 4;
            i++;
        }
    }
    cout << t << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while (t--) solve();
    return 0;
}
