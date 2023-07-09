#include <bits/stdc++.h>
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10LL
// #define int long long
const ll MOD = 1000000007LL;

// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

int s, n, k, r1, r2, c1, c2;
int Size = 1;
int arr[50][50];
void go(int x, int y) {
    int time = 0;
    bool ok = false;
    int nowR1 = 0, nowC1 = 0;
    int nowR2 = Size, nowC2 = Size;
    while(time < s && !ok){
        int p = (nowR2 - nowR1) / n;
        int q = (nowC2 - nowC1) / n;
        if (x >= nowR1 + (n - k) / 2 * p && x < nowR2 - (n - k) / 2 * p && y >= nowC1 + (n - k) / 2 * q && y < nowC2 - (n - k) / 2 * q) {
            ok = true;
        }
        else {
            for (int i = 0; i < n; i++)
            {
                if (x >= nowR1 + i * p && x < nowR1 + (i + 1) * p) {
                    nowR2 = nowR1 + (i + 1) * p;
                    nowR1 = nowR1 + i * p;
                    break;
                }
            }
            for (int i = 0; i < n; i++)
            {
                if (y >= nowC1 + i * q && y < nowC1 + (i + 1) * q) {
                    nowC2 = nowC1 + (i + 1) * q;
                    nowC1 = nowC1 + i * q;
                    break;
                }
            }
        }
        time++;
    }
    if (ok)arr[x - r1][y - c1] = 1;
    else arr[x - r1][y - c1] = 0;
}

void Solve() {
    cin >> s >> n >> k >> r1 >> r2 >> c1 >> c2;
    for (int i = 0; i < s; i++)
    {
        Size *= n;
    }
    for (int i = r1; i <= r2; i++)
    {
        for (int j = c1; j <=c2; j++)
        {
            go(i, j);
            cout << arr[i-r1][j-c1];
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--) Solve();
    return 0;
}