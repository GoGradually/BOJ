#include <bits/stdc++.h>
using namespace std;
int main(){
    string str;
    int n;
    cin>>n>>str;
    int ans= 0;
    for(int i = 0; i<n; i++){
        ans += str[i]-'A'+1;
    }
    cout<<ans;
    return 0;
}