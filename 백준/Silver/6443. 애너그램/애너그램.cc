#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <cstring>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int dp[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while (n--) {
        string str;
        cin >> str;
        int arr[26];
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < str.size(); i++) {
            arr[str[i] - 'a']++;
        }
        vector<int> perm;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < arr[i]; j++) {
                perm.push_back(i);
            }
        }
        do {
            for (int i = 0; i < perm.size(); i++) {
                char c = char('a' + perm[i]);
                cout << c;
            }
            cout << '\n';
        } while (next_permutation(perm.begin(), perm.end()));
    }
    return 0;
}