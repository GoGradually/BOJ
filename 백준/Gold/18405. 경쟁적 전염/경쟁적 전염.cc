#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <tuple>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };
int arr[200][200];
int check[200][200];
int n, k;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    vector<tuple<int, int, int>> temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] != 0)temp.push_back({ arr[i][j], i, j });
        }
    }
    sort(temp.begin(), temp.end());
    queue<pair<int, int>> bfsQ;
    memset(check, -1, sizeof(check));
    for (int i = 0; i < temp.size(); i++)
    {
        int num, a, b;
        tie(num, a, b) = temp[i];
        bfsQ.push(make_pair(a, b));
        check[a][b] = 0;
    }
    while (!bfsQ.empty()) {
        int x, y;
        tie(x, y) = bfsQ.front();
        bfsQ.pop();
        for (int k = 0; k < 4; k++)
        {
            int p = x + dx[k], q = y + dy[k];
            if (p>=0&&p<n&&q>=0&&q<n&&check[p][q] == -1) {
                check[p][q] = check[x][y]+1;
                arr[p][q] = arr[x][y];
                bfsQ.push(make_pair(p, q));
            }
        }
    }
    int s, x, y;
    cin >> s >> x >> y;
    if (check[x-1][y-1] > s) cout << 0 << '\n';
    else cout << arr[x-1][y-1] << '\n';
    return 0;
}