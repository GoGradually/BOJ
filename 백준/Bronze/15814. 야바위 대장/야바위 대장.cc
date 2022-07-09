#include <bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin>>str;
    int t;
    cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        swap(str[a], str[b]);
    }
    cout<<str;
    return 0;
}