#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    bool check[100001];
    memset(check, true, sizeof(check));
    check[1] = false;
    check[0] = false;
    for (int i = 2; i * i <= 100000; i++) {
        if (check[i]){
            for (int j = 2; i * j <= 100000; j++) {
                check[i * j] = false;
            }
        }
    }
    vector<int> prime;
    for (int i = 2; i < 100001; i++) {
        if (check[i]) prime.push_back(i);
    }
    int ans = 0;
    for (int t = a; t <= b; t++) {
        int now = t;
        int cnt = 0;
        int i = 0;
        while (now != 1 && i != prime.size()) {
            if (now % prime[i] == 0) {
                cnt++;
                now /= prime[i];
            } else {
                i++;
            }
        }
        if (check[cnt]) ans++;
    }
    cout << ans << '\n';
}
int main(int argc, const char* argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t = 1;
    while (t--) solve();
    return 0;
}
