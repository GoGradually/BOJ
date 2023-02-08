#include <bits/stdc++.h>
using namespace std;

int arr[10] = {1, 2, 4, 8, 1, 3, 6, 1, 2, 5};

void solve() {
    int a, b;
    cin >> a >> b;
    long long e = 1;
    a++;
    for (int i = 0; i < a; i++) {
        e *= 2;
    }
    while (a <= 62) {
        long long temp = e;
        while (temp / 10 != 0) {
            temp /= 10;
        }
        if (b == temp) break;
        a++;
        e *= 2;
    }
    if (a == 63) {
        cout << 0 << '\n';
    } else {
        cout << a << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) solve();
    return 0;
}
