#include <bits/stdc++.h>
using namespace std;

int main(){
    double a, b;
    cin>>a>>b;
    double temp = (b - a)/400;
    double ans = 1 / (1 + pow(10, temp));
    cout<<ans<<'\n';
    return 0;
}