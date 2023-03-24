#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<bool> card(n * 2 + 1);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        card[arr[i]] = true;
    }
    multiset<int> round1, round2;
    for (int i = 1; i <= 2 * n; i++) {
        if (!card[i]) {
            if (round2.size() < n / 2)
                round2.insert(i);
            else
                round1.insert(i);
        }
    }
    int ans = 0;
    for (int i = 0; i < n / 2; i++) {
        auto it = round1.lower_bound(arr[i]);
        if (it == round1.end()) continue;
        round1.erase(it);
        ans++;
    }
    for (int i = n / 2; i < n; i++) {
        auto it = round2.upper_bound(arr[i]);
        if (it == round2.begin()) continue;
        it--;
        round2.erase(it);
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