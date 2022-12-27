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
    vector<int> arr(501);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr[a] = b;
    }
    vector<int> D;
    for (int i = 0; i < 501; i++) {
        int ind = lower_bound(D.begin(), D.end(), arr[i]) - D.begin();
        if(ind == D.size())D.push_back(arr[i]);
        else D[ind] = arr[i];
    }
    cout<<n - (D.size()-1)<<'\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
