#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> ans(n, 0);
    bool ok = false;
    for (int a = n; a > 0; a--) {
        int b = n - a;
        if (a * b >= k) {
            ok = true;
            int now = n - 1;
            int frontA = a;
            while (now >= 0) {
                if (frontA <= k) {
                    k -= frontA;
                    ans[now] = 1;
                    now--;
                }
                else{
                    frontA--;
                    now--;
                }
            }
            break;
        }
    }
    if (!ok) {
        cout << -1 << '\n';
    } else {
        for (int i = 0; i < ans.size(); i++) {
            cout << char(ans[i] + 'A');
        }
        cout << '\n';
    }
}

int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while (t--) solve();
    return 0;
}
