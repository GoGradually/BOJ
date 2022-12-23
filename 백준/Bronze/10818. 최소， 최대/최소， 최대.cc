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
    cin>>n;
    vector<int> arr(n);
    int mx = -1000000, mn = 1000000;
    for (int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    for (int i = 0; i<n; i++) {
        mx = max(mx, arr[i]);
        mn = min(mn, arr[i]);
    }
    cout<<mn<<' '<<mx<<'\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
