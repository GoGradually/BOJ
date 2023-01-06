#include <algorithm>
#include <array>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define MOD 1000000000LL
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10
using namespace std;

bool check[100000001];
vector<int> prime;
void solve(int a) {
    if (a < 8) {
        cout << "Impossible.\n";
        return;
    } else if (a == 8) {
        cout << 2 << ' ' << 2 << ' ' << 2 << ' ' << 2 << '\n';
        return;
    }
    if (a % 2 == 1) {
        cout << 2 << ' ';
        a -= 2;
    }
    if (a % 2 == 0) {
        cout << 3 << ' ';
        a -= 3;
    }
    for (int i = 0; i < prime.size(); i++) {
        for (int j = 0; j < prime.size(); j++) {
            for (int k = 0; k < prime.size(); k++) {
                if (prime[i] + prime[j] + prime[k] == a) {
                    cout << prime[i] << ' ' << prime[j] << ' ' << prime[k]
                         << '\n';
                    return;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    memset(check, true, sizeof(check));
    check[1] = false;
    for (int i = 2; i * i <= 100000000; i++) {
        if (check[i]) {
            prime.push_back(i);
            for (int j = 2; j * i <= 100000000; j++) {
                check[i * j] = false;
            }
        }
    }

    while (cin>>t) solve(t);
    return 0;
}
