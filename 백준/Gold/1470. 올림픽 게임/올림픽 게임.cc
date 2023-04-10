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

vector<int> g[200001];

void Solve() {
    int n, l;
    cin >> n >> l;
    int ans = 1;
    vector<pair<int, int>> arr;
    int m1, m2, m3;
    cin >> m1 >> m2 >> m3;
    m1 += l;
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a > m1)
            ans++;
        else if (a == m1) {
            if (m2 - b + m3 - c + 1 > l) {
                arr.push_back({m2 - b + 1, -1});
            } else
                arr.push_back({m2 - b, m3 - c});
        }
    }
    int start = ans;
    sort(arr.begin(), arr.end());
    int now2 = l, now3 = l;
    int val = start;
    priority_queue<int, vector<int>, greater<int>> bronze;
    for (int j = 0; j < arr.size(); j++) {
        int b, c;
        tie(b, c) = arr[j];
        if (b < 0)
            val++;
        else if (c < 0) {
            now2 -= b;
            val++;
        } else {
            bronze.push(c + 1);
            now2 -= b + 1;
            val++;
        }
        while (!bronze.empty() && now2 < 0 && now3 >= bronze.top()) {
            now3 -= bronze.top();
            bronze.pop();
            now2++;
        }
        if (now2 < 0) {
            val--;
            break;
        }
        if (val > ans) ans = val;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) Solve();
    return 0;
}
