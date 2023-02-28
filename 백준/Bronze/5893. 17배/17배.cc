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
#define MOD 998244353
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;

void solve() {
    string str;
    cin >> str;
    string str2 = "0000" + str;
    str += "0000";
    int ind = 0;
    int carry = 0;
    string ans = "";
    while (ind < str2.length()) {
        int i = str.length() - 1 - ind;
        int j = str2.length() - 1 - ind;
        int a = str[i] - '0';
        int b = str2[j] - '0';
        int c = a + b + carry;
        if (c / 2 == 1) {
            carry = 1;
        } else {
            carry = 0;
        }
        if (c % 2 == 1) {
            ans = ans + '1';
        } else {
            ans += '0';
        }
        ind++;
    }
    if (carry == 1) {
        ans = ans + '1';
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
