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

int go(int now, int k, int length) {
    if (k == 0) {
        if (now == 1)
            return 1;
        else
            return 0;
    }
    int l = length - k - 3;
    l /= 2;
    if (now > l && now <= l + k + 3) {
        now -= l;
        if (now == 1)
            return 1;
        else
            return 0;
    }
    else if(now<=l){
        return go(now, k-1, l);
    }
    else{
        return go(now-l - k - 3, k-1, l);
    }
}

void solve() {
    int n;
    cin >> n;
    int k = 0;
    int length = 3;
    while (n > length) {
        k++;
        length = k + 3 + length * 2;
    }
    if(go(n, k, length) == 1) cout<<'m'<<'\n';
    else cout<<'o'<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
