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
    vector<int> red(n);
    vector<int> blue(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (i == 0 || arr[i] > red[i - 1]) {
            red[i] = arr[i];
        } else {
            red[i] = red[i - 1];
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1 || arr[i] > blue[i + 1]) {
            blue[i] = arr[i];
        } else {
            blue[i] = blue[i + 1];
        }
    }
    int redCnt = 0, blueCnt = 0;
    for (int i = 0; i < n - 1; i++) {
        if (red[i] > blue[i + 1])
            redCnt++;
        else if (red[i] < blue[i + 1])
            blueCnt++;
    }
    if (redCnt > blueCnt) cout << "R\n";
    else if (redCnt < blueCnt)
        cout << "B\n";
    else
        cout << "X\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
