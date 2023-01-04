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
    string str;
    cin>>str;
    int n = str.size();
    bool check = false;
    int frame = 1;
    vector<int> arr(n+5, 0);
    int ans = 0;
    //모든 배열 수치화
    for (int i = 0; i<n; i++) {
        if(str[i] == '-'){
            arr[i] = 0;
            if(check == true)
            {
                frame++;
                check = false;
            }
            else check = true;
        }
        else if(str[i] == 'P'){
            arr[i] = 10 - arr[i-1];
            check = false;
            frame++;
        }
        else if(str[i] == 'S'){
            arr[i] = 10;
            check = false;
            frame++;
        }
        else{
            arr[i] = str[i]-'0';
            if(check == true)
            {
                frame++;
                check = false;
            }
            else check = true;
        }
        ans+=arr[i];
    }
    //스페어 스트라이크 처리
    for (int i = 0; i<n; i++) {
        if(str[i] == 'P'){
            ans += arr[i+1];
        }
        if(str[i] == 'S'){
            ans += arr[i+1] + arr[i+2];
        }
    }
    if(str[n-3] == 'S' && frame != 11){            //S 3 5로 10프레임에 끝나면 이거 하면 안됨
        ans -= arr[n-2]+arr[n-1];
    }
    if(str[n-2] == 'P' || str[n-2] == 'S') {//마지막 스페어인가? 반드시 그렇다. 한프레임은 두번의 기회.
        ans -= arr[n-1];
    }
    cout<<ans<<'\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
