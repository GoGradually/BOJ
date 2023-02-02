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

int gcd(int a, int b){
    if(b>a)swap(a,b);
    if(b==0) return a;
    return gcd(b,a%b);
}

void solve() {
    int a, b;
    cin>>a>>b;
    cout<<a*b/gcd(a,b)<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin>>t;
    while (t--) solve();
    return 0;
}
