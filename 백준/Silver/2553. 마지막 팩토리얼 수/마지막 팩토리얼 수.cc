#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

long long arr[20001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    arr[1] = 1;
    for (int i = 2; i <= n; i++) {
        arr[i] = arr[i - 1] * i;
        while (arr[i] % 10 == 0) {
            arr[i] /= 10;
        }
        arr[i] %= 100000000;
    }
    while (arr[n] % 10 == 0) {
        arr[n] /= 10;
    }
    cout << arr[n] % 10 << '\n';
    return 0;
}