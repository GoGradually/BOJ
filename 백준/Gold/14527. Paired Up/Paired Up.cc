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
#define MOD 1000000007
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> arr(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr[i] = {b, a};
    }
    sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    ll ans = 0;
    while (left < right) {
        if (arr[left].second > arr[right].second) {
            arr[left].second -= arr[right].second;
            ans = max(ans, arr[left].first + arr[right].first);
            right--;
        } else if (arr[left].second < arr[right].second) {
            arr[right].second -= arr[left].second;
            ans = max(ans, arr[left].first + arr[right].first);
            left++;
        } else {
            ans = max(ans, arr[left].first + arr[right].first);
            left++;
            right--;
        }
    }
    if(left==right){
        ans = max(ans, arr[left].first + arr[right].first);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
