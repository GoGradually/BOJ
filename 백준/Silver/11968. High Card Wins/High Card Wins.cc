#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<bool> arr(2*n+1);
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr[temp] = true;
    }
    int ans = 0;
    int cnt = 0;
    for (int i = 1; i <= 2*n; i++)
    {
        if (arr[i]) cnt++;
        else {
            if (cnt == 0)continue;
            ans++;
            cnt--;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}