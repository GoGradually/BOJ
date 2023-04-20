#include <bits/stdc++.h>
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10LL
const ll MOD = 998244353;
using namespace std;

vector<pair<int, int>> g[100001];
vector<int> arr;

ll need[2];

void Solve() {
    int num;
    cin >> num;
    int n = (1 << num);
    vector<vector<int>> arr(n, vector<int>(n, 0));
    vector<char> command(n);
    map<char, int> comCount;
    for (int i = 0; i < n; i++) {
        cin >> command[i];
        comCount[command[i]]++;
    }
    int startX = 0, startY = 0;
    int xSize = n / 2, ySize = n / 2;
    for (int i = 0; i < n; i++) {
        if (command[i] == 'L') {
            ySize /= 2;
        } else if (command[i] == 'R') {
            startY += ySize;
            ySize /= 2;
        } else if (command[i] == 'D') {
            startX += xSize;
            xSize /= 2;
        } else {
            xSize /= 2;
        }
    }
    cin >> arr[startX][startY];
    xSize = 1, ySize = 1;
    for (int i = n - 1; i >= 0; i--) {
        if (command[i] == 'L') {
            for (int i = startX; i < startX + xSize; i++) {
                for (int j = 0; j < ySize; j++) {
                    int prev = startY + ySize - 1 - j;
                    int next = startY + ySize + j;
                    if (arr[i][prev] == 3) arr[i][next] = 2;
                    if (arr[i][prev] == 2) arr[i][next] = 3;
                    if (arr[i][prev] == 1) arr[i][next] = 0;
                    if (arr[i][prev] == 0) arr[i][next] = 1;
                }
            }
            ySize *= 2;
        } else if (command[i] == 'R') {
            startY -= ySize;
            for (int i = startX; i < startX + xSize; i++) {
                for (int j = 0; j < ySize; j++) {
                    int next = startY + ySize - 1 - j;
                    int prev = startY + ySize + j;
                    if (arr[i][prev] == 3) arr[i][next] = 2;
                    if (arr[i][prev] == 2) arr[i][next] = 3;
                    if (arr[i][prev] == 1) arr[i][next] = 0;
                    if (arr[i][prev] == 0) arr[i][next] = 1;
                }
            }
            ySize *= 2;
        } else if (command[i] == 'D') {
            startX -= xSize;
            for (int i = startY; i < startY + ySize; i++) {
                for (int j = 0; j < xSize; j++) {
                    int next = startX + xSize - 1 - j;
                    int prev = startX + xSize + j;
                    if (arr[prev][i] == 3) arr[next][i] = 1;
                    if (arr[prev][i] == 2) arr[next][i] = 0;
                    if (arr[prev][i] == 1) arr[next][i] = 3;
                    if (arr[prev][i] == 0) arr[next][i] = 2;
                }
            }
            xSize *= 2;
        } else {
            for (int i = startY; i < startY + ySize; i++) {
                for (int j = 0; j < xSize; j++) {
                    int prev = startX + xSize - 1 - j;
                    int next = startX + xSize + j;
                    if (arr[prev][i] == 3) arr[next][i] = 1;
                    if (arr[prev][i] == 2) arr[next][i] = 0;
                    if (arr[prev][i] == 1) arr[next][i] = 3;
                    if (arr[prev][i] == 0) arr[next][i] = 2;
                }
            }
            xSize *= 2;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) Solve();
    return 0;
}