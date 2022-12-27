#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define MOD 1000000000LL
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;

bool check[10000001];
bool chk[10000001];
void solve() {
    memset(chk, false, sizeof(chk));
    string str;
    cin >> str;
    vector<int> arr(str.size());
    for (int i = 0; i < str.size(); i++) {
        arr[i] = str[i] - '0';
    }
    sort(arr.begin(), arr.end());
    int ans = 0;
    for (int i = 0; i < (1 << str.size()); i++) {
        vector<int> now;
        for (int j = 0; j < str.size(); j++) {
            if (i & (1 << j)) now.push_back(arr[j]);
        }
        do {
            int val = 0;
            for (int j = 0; j < now.size(); j++) {
                val *= 10;
                val += now[j];
            }
            if (!chk[val] && check[val]) {
                ans++;
                chk[val] = true;
            }
        } while (next_permutation(now.begin(), now.end()));
    }
    cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    memset(check, true, sizeof(check));
    check[0] = false;
    check[1] = false;
    for (int i = 2; i * i < 10000001; i++) {
        if (check[i]) {
            for (int j = 2; i * j < 10000001; j++) {
                check[i * j] = false;
            }
        }
    }
    cin >> t;
    while (t--) solve();
    return 0;
}
