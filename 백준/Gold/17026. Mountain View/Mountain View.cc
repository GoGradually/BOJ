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

vector<pair<int, int>> arr;
bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back({a - b, b});
    }
    sort(arr.begin(), arr.end(), cmp);
    ll ans = 1;
    stack<pair<int, int>> stk;
    stk.push(arr[0]);
    for (int i = 1; i < n; i++) {
        if (arr[i].first == arr[i - 1].first) {
            continue;
        }
        int nowPeakX = arr[i].first + arr[i].second;
        int nowPeakY = arr[i].second;
        int lastPeakX = stk.top().first + stk.top().second;
        int lastPeakY = stk.top().second - abs(lastPeakX - nowPeakX);
        if (nowPeakY > lastPeakY) {
            stk.push(arr[i]);
            ans++;
        }
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
