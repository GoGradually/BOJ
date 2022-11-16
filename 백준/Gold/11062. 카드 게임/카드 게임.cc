#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
pair<int, int> dp[1001][1001];
int arr[1001];
pair<int, int> go(int left, int right) {
    pair<int, int>& ret = dp[left][right];
    if (ret.first != -1) return ret;
    if (left == right) return {arr[left], 0};
    if (go(left + 1, right).second + arr[left] >=
        go(left, right - 1).second + arr[right])
        return ret = {go(left + 1, right).second + arr[left],
                      go(left + 1, right).first};
    else
        return ret = {go(left, right - 1).second + arr[right],
                      go(left, right - 1).first};
}
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << go(0, n - 1).first << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}