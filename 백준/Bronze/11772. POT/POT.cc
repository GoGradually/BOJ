#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    long long ans=0;
    for(int i = 0; i<n; i++){
        int temp;
        cin>>temp;
        long long val = pow(temp/10, temp%10);
        ans+=val;
    }
    cout<<ans<<'\n';
    return 0;
}