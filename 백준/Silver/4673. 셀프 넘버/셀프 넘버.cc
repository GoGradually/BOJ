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

bool check[10001];
void solve() {
    for (int i = 1; i<10001; i++) {
        if(!check[i]){
            int j = i;
            while(j<10001){
                int now = j;
                int val = now;
                while(now!=0){
                    val += now%10;
                    now/=10;
                }
                if(val<10001) check[val] = true;
                j = val;
            }
        }
    }
    for (int i = 1; i<10001; i++) {
        if(!check[i]) cout<<i<<'\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(5);
    int t = 1;
    while (t--) solve();
    return 0;
}
