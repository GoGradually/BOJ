#include <bits/stdc++.h>
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
#define MOD 1000000007LL;
/*
#include "atcoder/modint.hpp"
using mint = atcoder::modint998244353;
*/

using namespace std;

void Solve() {
    int n;
    cin >> n;
    vector<ll> arr(n), psum(n + 1), minVal(n, INF);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        psum[i + 1] = psum[i] + arr[i];
    }
    minVal[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        minVal[i] = min(minVal[i + 1], arr[i]);
    }
    ll ansVal = 0;
    ll ansDiv = INF;
    ll ans = 0;
    vector<ll> ansArr;
    for (int i = 0; i < n - 2; i++) {
        ll val =
        (psum[n] - psum[i + 1] - minVal[i + 1]);
        ll div = (n - (i + 1) - 1);
        if (ansDiv * val > ansVal * div) {
            ansArr.clear();
            ans = i + 1;
            ansArr.push_back(ans);
            ansDiv = div;
            ansVal = val;
        }else if(ansDiv * val == ansVal * div){
            ans = i + 1;
            ansArr.push_back(ans);
        }
    }
    sort(ansArr.begin(), ansArr.end());
    for (ll a : ansArr) {
        cout<<a<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--) Solve();
    return 0;
}
