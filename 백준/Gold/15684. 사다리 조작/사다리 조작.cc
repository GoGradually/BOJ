#include <iostream>
#include <tuple>

using namespace std;

int n, h, m;
int arr[30][10];
int minLine = 5;

tuple<int, int> WhereB(int t) {
    int row = t / (n - 1);
    int column = t % (n - 1);
    return tuple<int, int>(row, column);
}

bool ladder(int num) {
    bool ans = false;
    int now = num;
    for (int i = 0; i < h; i++)
    {
        if (arr[i][now] == 1) now = now + 1;
        else if (arr[i][now - 1] == 1) now = now - 1;
    }

    if (now == num) return true;
    else return false;
}

void putLine(int t, int count) {
    if (t == h * (n - 1) || count >= 3) {
        bool check = true;
        for (int i = 0; i < n; i++) {
            if (ladder(i) == false) {
                check = false;
                break;
            }
        }
        if (check) {  // check
            if (minLine > count) {
                minLine = count;
            }
        }
        return;
    }
    tuple<int, int> xy = WhereB(t);
    int row = get<0>(xy);
    int column = get<1>(xy);
    putLine(t + 1, count);
    bool attach = false;
    for (int i = -1; i <= 1; i++)
    {
        if (column + i >= 0 && column + i < n - 1 && arr[row][column + i] == 1)
            attach = true;
    }
    if (!attach) {
        arr[row][column] = 1;
        putLine(t + 1, count + 1);
        arr[row][column] = 0;
    }
}
int main() {
    cin >> n >> m >> h;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        arr[a-1][b-1] = 1;
    }
    putLine(0, 0);
    if (minLine == 5) cout << -1 << '\n';
    else cout << minLine << '\n';
    return 0;
}