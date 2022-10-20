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
void solve() {
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if (n == 1) {
        cout << 'A' << '\n';
        return;
    }
    vector<ll> ans;
    for (ll i = -1000000; i <= 1000000; i++) {
        ll j;
        j = arr[1] - arr[0] * i;
        bool ok = true;
        for (int k = 1; k < n - 1; k++) {
            if (arr[k] * i + j != arr[k + 1]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans.push_back(arr[n - 1] * i + j);
        }
    }
    if (ans.size() == 0) cout << 'B' << '\n';
    else if (ans.size() == 1|| (ans.size()>=2&&ans[0]==ans[1])) {
        cout << ans[0] << '\n';
    }
    else {
        cout << 'A' << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while (t--) solve();
    return 0;
}
