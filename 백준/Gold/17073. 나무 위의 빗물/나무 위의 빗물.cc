#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(11);
    int t;
    double n;
    cin >> t >> n;
    vector<int> d(t + 1, 0);
    for (int i = 0; i < t-1; i++)
    {
        int a, b;
        cin >> a >> b;
        d[a]++;
        d[b]++;
    }
    double ans = 0;
    for (int i = 2; i <=t; i++)
    {
        if (d[i] == 1)ans+=1;
    }
    cout << (double)n / (double)ans;
    return 0;
}