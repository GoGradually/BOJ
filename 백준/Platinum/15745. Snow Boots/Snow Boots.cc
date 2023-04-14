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

vector<int> arr, arrID;
vector<int> deep, dist, bid;

bool comp(int a, int b) { return arr[a] > arr[b]; }
bool bComp(int a, int b) { return deep[a] > deep[b]; }

void Solve() {
    int n, b;
    cin >> n >> b;
    arr.resize(n);
    arrID.resize(n);
    deep.resize(b);
    dist.resize(b);
    bid.resize(b);
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        s.insert(i);
        arrID[i] = i;
    }
    sort(arrID.begin(), arrID.end(), comp);

    for (int i = 0; i < b; i++) {
        cin >> deep[i] >> dist[i];
        bid[i] = i;
    }
    sort(bid.begin(), bid.end(), bComp);
    multiset<int> tileDist;
    for (int i = 0; i < n - 1; i++) {
        tileDist.insert(1);
    }
    int j = 0;
    vector<int> ans(b);
    for (int i = 0; i < b; i++) {
        while (j < n && deep[bid[i]] < arr[arrID[j]]) {
            auto it = s.find(arrID[j]);
            if (it == s.begin()) continue;
            if (it == s.end()) continue;
            set<int>::iterator prev = --it;
            it++;
            set<int>::iterator next = ++it;
            it--;
            tileDist.erase(tileDist.find(*it - *prev));
            tileDist.erase(tileDist.find(*next - *it));
            tileDist.insert(*next - *prev);
            s.erase(it);
            j++;
        }
        if (*tileDist.rbegin() > dist[bid[i]]) {
            ans[bid[i]] = 0;
        } else {
            ans[bid[i]] = 1;
        }
    }
    for (int i = 0; i < b; i++) {
        cout << ans[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--) Solve();
    return 0;
}
