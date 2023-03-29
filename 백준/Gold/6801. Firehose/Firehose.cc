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
vector<int> arr;
int n, k;

bool check(int x) {
    int cnt = 0;
    int start = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] - start > x) {
            start = arr[i];
            cnt++;
        }
    }
    cnt++;
    if (cnt > k)
        return false;
    else
        return true;
}

int first_true(int lo, int hi) {
    hi++;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

void solve() {
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> k;
    int minVal = 2000000;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(i==j)continue;
            arr[j] = (arr[j] - arr[i] + 1000000) % 1000000;
        }
        arr[i] = 0;
        sort(arr.begin(), arr.end());
        minVal = min(minVal, first_true(0, 2000000));
    }
    if (minVal % 2 == 1) minVal++;
    cout << minVal / 2 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
