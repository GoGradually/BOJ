#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;

void solve() {
    int n, g;
    cin >> n >> g;
    map<int, int> cnt;
    map<int, int> m;
    cnt[g] = 100000000;
    vector<tuple<int, int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        int day, id, change;
        cin >> day >> id >> change;
        arr[i] = {day, id, change};
    }
    sort(arr.begin(), arr.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int day, id, change;
        tie(day, id, change) = arr[i];
        auto beforeIt = cnt.end();
        beforeIt--;
        int beforeTopProduced = beforeIt->first;
        int beforeTopCnt = beforeIt->second;

        if (m.count(id) == 0) {
            m[id] = g;
        }
        bool IwasTop = cnt[m[id]] == 1 && beforeTopProduced == m[id];

        cnt[m[id]]--;
        if (cnt[m[id]] == 0) cnt.erase(m[id]);
        m[id] += change;
        cnt[m[id]]++;

        auto afterIt = cnt.end();
        afterIt--;
        int afterTopProduced = afterIt->first;
        int afterTopCnt = afterIt->second;
        bool IamTop = cnt[m[id]] == 1 && afterTopProduced == m[id];
        if (IwasTop && IamTop) continue;
        if (beforeTopProduced != afterTopProduced ||
            beforeTopCnt != afterTopCnt)
            ans++;
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