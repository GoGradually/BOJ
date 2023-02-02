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
#define MOD 998244353
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;

void solve() {
    while (true) {
        int a, b;
        cin>>a>>b;
        if(a==0&&b==0)break;
        if(a%b==0){
            cout<<"multiple\n";
        }else if (b%a==0){
            cout<<"factor\n";
        }else{
            cout<<"neither\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
