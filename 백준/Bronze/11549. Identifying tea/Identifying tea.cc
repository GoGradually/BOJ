#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a, ans = 0;
    for(int i = 0; i<5; i++){
        cin>>a;
        if(a==n)
            ans++;
    }
    cout<<ans;
    return 0;
}