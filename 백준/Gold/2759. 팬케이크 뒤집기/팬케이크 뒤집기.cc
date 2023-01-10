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
    vector<int> ans;
    for (int i = n; i > 0; i--) {
        for (int j = 0; j < i - 1; j++) {
            if (arr[j] == i) {
                if (j != 0) {
                    ans.push_back(j + 1);
                    reverse(arr.begin(), arr.begin()+j+1);
                }
                ans.push_back(i);
                reverse(arr.begin(), arr.begin()+i);
            }
        }
    }
    cout << ans.size() << ' ';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
