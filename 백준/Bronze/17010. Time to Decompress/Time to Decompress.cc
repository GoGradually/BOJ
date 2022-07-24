#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        char a;
        cin>>n>>a;
        for(int i = 0; i<n; i++){
            cout<<a;
        }
        cout<<'\n';
    }
    return 0;
}