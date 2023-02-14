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

int w, h, l1, l2;

int gcd(int a, int b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a % b);
}
bool check(int a, int b) {
    int GCD = gcd(a, b);
    if(GCD==1){
        if(a*a+b*b>l2*l2) return false;
        if(a*a+b*b<l1*l1) return false;
        return true;
    }
    else return false;
}
void solve() {
    cin >> w >> h >> l1 >> l2;
    ll ans = 0;
    if(w>h)swap(w, h);
    for (int i = 0; i<=w; i++) {
        for (int j = 0; j<=h; j++) {
            if (check(i, j)) {
                ans += (w - i + 1) * (h - j + 1) * 2;
                if(i==0||j==0)ans-=(w - i + 1) * (h - j + 1);
            }
        }
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
