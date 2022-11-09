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
#define MOD 998244353LL
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;
int arr[2001];
int ok[2001][2001];
int go(int left, int right){
    if(ok[left][right] != -1) return ok[left][right];
    if(left==right || left>right) return ok[left][right] = 1;
    if(arr[left]==arr[right]) return ok[left][right] = go(left+1, right-1);
    else return ok[left][right] = 0;
}
void solve() {
    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> m;
    memset(ok, -1, sizeof(ok));

    for (int i = 0; i < m; i++) {
        int left, right;
        cin >> left >> right;
        left--;
        right--;
        cout<<go(left, right)<<'\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
