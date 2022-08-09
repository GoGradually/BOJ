#include <bits/stdc++.h>
using namespace std;
int n;
int arr[11][11];
int go(vector<bool>& check, int index, int val) {
    if (index == 11) {
        for (int i = 0; i < 11; i++)
        {
            if (check[i] == false) return 0;
        }
        return val;
    }
    int ret = 0;
    for (int i = 0; i < 11; i++) {
        if (arr[index][i] > 0 && check[i] == false) {
            check[i] = true;
            int temp = go(check, index + 1,val+arr[index][i]);
            ret = ret < temp ? temp : ret;
            check[i] = false;
        }
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 11; j++) {
                cin >> arr[i][j];
            }
        }
        vector<bool> check(11, false);
        int ans = go(check, 0, 0);
        cout << ans << '\n';
    }

    return 0;
}