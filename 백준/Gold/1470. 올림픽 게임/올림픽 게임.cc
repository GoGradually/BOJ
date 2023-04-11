#include <bits/stdc++.h>
using namespace std;

int main() {
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
        if(ans < val) ans = val;
    }
    cout << ans << '\n';
    return 0;
}
