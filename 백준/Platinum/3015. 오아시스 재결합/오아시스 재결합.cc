#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    long long sum = 0;
    stack<pair<int, int>> stk;
    for(int i = 0; i<n; i++){
        int a;
        cin>>a;
        int cnt = 0;
        while(!stk.empty() && stk.top().first < a) {
            cnt += stk.top().second;
            stk.pop();
        } 
        int aCnt = 1;        
        if (!stk.empty() && stk.top().first == a) {
            aCnt+=stk.top().second;
            stk.pop();
        }
        cnt += aCnt - 1;
        sum += cnt;
        if(!stk.empty())sum++;
        stk.push({a, aCnt});
    }
    cout<<sum<<'\n';
}