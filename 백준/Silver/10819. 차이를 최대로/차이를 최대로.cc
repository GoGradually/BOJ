#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int ans = 0;
    do {
        int ret = 0;
        for (int i = 0; i < n-1; i++)
        {
            ret += abs(arr[i + 1] - arr[i]);
        }
        if (ret > ans)ans = ret;
    } while (next_permutation(arr.begin(), arr.end()));
    cout << ans;
    return 0;
}