#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int max_sum = arr[0], cur_sum = 0;
    for (int i = 0; i < n; i++) {
        cur_sum = max(arr[i], cur_sum + arr[i]);
        max_sum = max(max_sum, cur_sum);
    }

    cout << max_sum << endl;

    return 0;
}
