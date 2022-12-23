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

void solve() {
    int n;
    cin >> n;
    vector<string> str(n);
    for (int i = 0; i < n; i++) {
        cin >> str[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        bool check[26] = {};
        bool ok = true;
        for (int j = 1; j < str[i].size(); j++) {
            if(str[i][j] != str[i][j-1]) {
                if(check[str[i][j-1]-'a']) ok = false;
                check[str[i][j-1]-'a'] = true;
            }
        }
        if(check[str[i][str[i].size()-1]-'a']) ok = false;
        check[str[i][str[i].size()-1]-'a'] = true;
        if(ok) ans++;
    }
    cout<<ans<<'\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
