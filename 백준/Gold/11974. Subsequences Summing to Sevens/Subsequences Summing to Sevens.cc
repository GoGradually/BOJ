#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void Solve() {
    int n;
    cin >> n;
    vector<ll> arr(n), psum(n + 1);
    vector<ll> num[7];
    num[0].push_back(0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        psum[i + 1] = psum[i] + arr[i];
        num[psum[i + 1] % 7].push_back(i + 1);
    }
    ll ans = 0;
    for (int i = 0; i < 7; i++) {
        if (num[i].empty())continue;
        ans = max(ans, num[i].back() - num[i].front());
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) Solve();
    return 0;
}