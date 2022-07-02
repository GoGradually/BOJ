#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back(make_pair(a, b));
    }
    int ans = 1000000001;
    for (int i = 1; i < (1 << n); i++) {
        int a = 1, b = 0;

        for (int j = 0; j < n; j++) {
            if (((1 << j) & i) != 0) {
                int p, q;
                tie(p, q) = arr[j];
                b += q;
                a *= p;
            }
        }
        ans = ans > abs(a - b) ? abs(a - b) : ans;
    }
    cout << ans << '\n';
    return 0;
}