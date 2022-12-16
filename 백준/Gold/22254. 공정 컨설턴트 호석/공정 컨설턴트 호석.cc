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
bool ok(int line, int time, vector<int> &arr) {
    priority_queue<int> factory;
    for (int i = 0; i < line; i++) {
        factory.push(0);
    }
    for (int i = 0; i < arr.size(); i++) {
        int now = -factory.top();
        factory.pop();
        now += arr[i];
        factory.push(-now);
    }
    while (!factory.empty()) {
        if (-factory.top() > time) return false;
        factory.pop();
    }
    return true;
}
void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int left = 0, right = 100000;
    while (left + 1 < right) {
        int mid = (left + right) / 2;
        if (ok(mid, x, arr))
            right = mid;
        else
            left = mid;
    }
    cout << right << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
