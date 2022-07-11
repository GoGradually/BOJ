#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m, r;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int row, col;
    cin >> row >> col;
    vector<string> planet(row);
    for (int i = 0; i < row; i++) {
        cin >> planet[i];
    }
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    int check[500][500];
    int ans = 0;
    int ansDir = 0;
    for (int t = 0; t < 4; t++) {
        memset(check, 0, sizeof(check));
        int cnt = 0;
        int direct = t;
        int nowX = x, nowY = y;
        while (nowX >= 0 && nowX < row && nowY >= 0 && nowY < col) {
            cnt++;
            check[nowX][nowY]++;
            if (check[nowX][nowY] == 3) {
                cnt = -1;
                break;
            }
            nowX += dx[direct];
            nowY += dy[direct];
            if (!(nowX >= 0 && nowX < row && nowY >= 0 && nowY < col))break;
            if (planet[nowX][nowY] == '\\') {
                if (direct == 3)
                    direct = 0;
                else if (direct == 0)
                    direct = 3;
                else if (direct == 2)
                    direct = 1;
                else
                    direct = 2;
            }
            if (planet[nowX][nowY] == '/') {
                if (direct == 0)
                    direct = 1;
                else if (direct == 1)
                    direct = 0;
                else if (direct == 2)
                    direct = 3;
                else
                    direct = 2;
            }
            if (planet[nowX][nowY] == 'C') {
                break;
            }
        }
        if (ans < cnt) {
            ans = cnt;
            ansDir = t;
        }
        if (cnt == -1) {
            ans = cnt;
            ansDir = t;
            break;
        }
    }
    if (ansDir == 0) {
        cout << "U\n";
    }
    if (ansDir == 1) {
        cout << "R\n";
    }
    if (ansDir == 2) {
        cout << "D\n";
    }
    if (ansDir == 3) {
        cout << "L\n";
    }
    if (ans == -1)
        cout << "Voyager\n";
    else
        cout << ans << '\n';

    return 0;
}