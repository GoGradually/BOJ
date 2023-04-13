#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10

using namespace std;

bool comp(pair<ll, ll> &a, pair<ll, ll> &b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

void Solve() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(), arr.end());
    vector<ll> maxF(n, 0), maxG(n, 0), minF(n, INF), minG(n, INF);
    maxF[0] = arr[0].second;
    minF[0] = arr[0].second;
    for (int i = 1; i < n; i++) {
        maxF[i] = max(maxF[i - 1], arr[i].second);
        minF[i] = min(minF[i - 1], arr[i].second);
    }
    maxG[n - 1] = arr[n - 1].second;
    minG[n - 1] = arr[n - 1].second;
    for (int i = n - 2; i >= 0; i--) {
        maxG[i] = max(maxG[i + 1], arr[i].second);
        minG[i] = min(minG[i + 1], arr[i].second);
    }
    ll val = (arr[n - 1].first - arr[0].first) * (maxF[n - 1] - minF[n - 1]);
    ll ret1 = val;
    for (int i = 0; i < n - 1; i++) {
        ll temp =
            (arr[i].first - arr[0].first) * (maxF[i] - minF[i]) +
            (arr[n - 1].first - arr[i + 1].first) * (maxG[i + 1] - minG[i + 1]);
        if (temp < ret1) ret1 = temp;
    }

    sort(arr.begin(), arr.end(), comp);
    maxF[0] = arr[0].first;
    minF[0] = arr[0].first;
    for (int i = 1; i < n; i++) {
        maxF[i] = max(maxF[i - 1], arr[i].first);
        minF[i] = min(minF[i - 1], arr[i].first);
    }
    maxG[n - 1] = arr[n - 1].first;
    minG[n - 1] = arr[n - 1].first;
    for (int i = n - 2; i >= 0; i--) {
        maxG[i] = max(maxG[i + 1], arr[i].first);
        minG[i] = min(minG[i + 1], arr[i].first);
    }
    ll ret2 = val;
    for (int i = 0; i < n - 1; i++) {
        ll temp = (arr[i].second - arr[0].second) * (maxF[i] - minF[i]) +
            (arr[n - 1].second - arr[i + 1].second) *
            (maxG[i + 1] - minG[i + 1]);
        if (temp < ret2) ret2 = temp;
    }
    cout << max(val - ret1, val - ret2) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) Solve();
    return 0;
}