#include <bits/stdc++.h>
using namespace std;

int n, m, r;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int arr[101][101];
        for (int i = 0; i < 101; i++)
        {
            for (int j = 0; j < 101; j++)
            {
                arr[i][j] = 100000000;
            }
        }
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            arr[a][b] = c;
            arr[b][a] = c;
        }
        int k;
        cin >> k;
        vector<int> mem(k);
        for (int i = 0; i < k; i++) {
            cin >> mem[i];
        }
        for (int i = 1; i <= n; i++) {
            arr[i][i] = 0;
        }
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (arr[i][j] > arr[i][k] + arr[k][j]) {
                        arr[i][j] = arr[i][k] + arr[k][j];
                    }
                }
            }
        }
        int ans = 1000000000;
        int ret = 0;
        for (int i = 1; i <=n; i++) {
            int val = 0;
            for (int j = 0; j < k; j++) {
                val += arr[mem[j]][i];
            }
            if (val < ans) {
                ans = val;
                ret = i;
            }
        }
        cout << ret << '\n';
    }
    return 0;
}