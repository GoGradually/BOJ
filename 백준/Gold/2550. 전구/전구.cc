#include <bits/stdc++.h>
using namespace std;
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a[10001][2];
    int p[10001];
    cin >> n;
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[j][i];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][0] == a[j][1]) {
                p[i] = j;
                break;
            }
        }
    }
    vector<int> d(n + 1), x(n + 1);
    int maxVal = 0, maxInd = 0;
    for (int i = 1; i <= n; i++) {
        int val = 0, ind = 0;
        for (int j = 0; j < i; j++) {
            if (val < d[j] && p[i] > p[j]) {
                val = d[j];
                ind = j;
            }
        }
        d[i] = val + 1;
        x[i] = ind;
        if (maxVal < d[i]) {
            maxVal = d[i];
            maxInd = i;
        }
    }
    cout << maxVal << '\n';
    vector<int> ans;
    while (maxInd != 0) {
        ans.push_back(a[maxInd][0]);
        maxInd = x[maxInd];
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ' ';
    }

    return 0;
}