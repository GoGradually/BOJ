#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i = 0; i<9; i++){
        int t;
        cin>>t;
        n-=t;
    }
    cout<<n<<'\n';
    return 0;
}