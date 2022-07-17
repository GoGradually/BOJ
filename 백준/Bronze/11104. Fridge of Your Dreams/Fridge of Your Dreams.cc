#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        int k = 1;
        int ans = 0;
        for (int j = 24 - 1; j >= 0; j--)
        {
            int now = str[j] - '0';
            ans += k * now;
            k *= 2;
        }
        cout << ans << '\n';
    }
    return 0;
}