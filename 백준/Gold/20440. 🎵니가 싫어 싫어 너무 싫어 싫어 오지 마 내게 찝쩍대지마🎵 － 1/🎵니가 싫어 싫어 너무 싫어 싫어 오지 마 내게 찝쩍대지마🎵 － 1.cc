#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <array>
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
    cin>>n;
    vector<pair<int, int>> arr(n+1);
    for (int i = 0; i<n; i++) {
        int a, b;
        cin>>a>>b;
        arr[i] = {a, b};
    }
    arr[n] = {2100000001, 2100000001};
    sort(arr.begin(), arr.end());
    map<int, int> dest;
    int maxCnt = 0;
    int Mstart = arr[0].first, Mend = 0;
    int start = 0, end = -1;
    priority_queue<int> pq;
    for (int i = 0; i<=n; i++) {
        while(!pq.empty() && -pq.top() <= arr[i].first){
            if(pq.size() > maxCnt) {
                maxCnt = pq.size();
                Mstart = start;
                Mend = -pq.top();
            }
            if(pq.size() == maxCnt && start == Mstart){
                Mend = -pq.top();
            }
            end = -pq.top();
            dest[end]++;
            pq.pop();
        }
        pq.push(-arr[i].second);
        if(end == arr[i].first&&dest[end]>0)dest[end]--;
        else start = arr[i].first;
    }
    cout<<maxCnt<<'\n';
    cout<<Mstart<<' '<<Mend<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
