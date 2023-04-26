#include <algorithm>
#include <array>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define MOD 998244353LL
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10

using namespace std;

void Solve() {
    string str;
    ll n;
    cin >> str >> n;
    ll s = str.length();
    while (s < n) s *= 2;
    if(s!=str.length()) s /= 2;
    while (s >= str.length()) {
        if (n > s) {
            n -= 1;
            n -= s;
        }
        if (n == 0) n += s;
        s /= 2;
    }
    cout << str[n - 1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--) Solve();
    return 0;
}
