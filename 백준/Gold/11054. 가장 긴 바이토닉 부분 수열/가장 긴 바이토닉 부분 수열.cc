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
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> arrr = arr;
    reverse(arrr.begin(), arrr.end());
    vector<int> d1, ind1(n), d2, ind2(n);
    for (int i = 0; i < n; i++) {
        int ind = lower_bound(d1.begin(), d1.end(), arr[i]) - d1.begin();
        if (ind == d1.size()) {
            d1.push_back(arr[i]);
        } else {
            d1[ind] = arr[i];
        }
        ind1[i] = ind+1;
    }
    for (int i = 0; i < n; i++) {
        int ind = lower_bound(d2.begin(), d2.end(), arrr[i]) - d2.begin();
        if (ind == d2.size()) {
            d2.push_back(arrr[i]);
        } else {
            d2[ind] = arrr[i];
        }
        ind2[i] = ind+1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int j = n - 1 - i;
        ans = max(ans, ind1[i] + ind2[j]);
    }
    cout << ans-1 << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
