#include <bits/stdc++.h>
#define ll long long
#define INF (int)1e9 + 10
#define lINF (ll)1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

void Solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
    }
    sort(arr.begin(), arr.end());
    int val = 1;
    for (int i = n - 1; i > 0; i--) {
        if (arr[i].first - m > arr[i - 1].first) {
            if (n - i > 3) {
                cout << "YES\n";
                cout << arr[i].second + 1 << ' ' << arr[i + 1].second + 1
                     << ' ';
                for (int j = 0; j < i; j++) {
                    cout << arr[j].second + 1 << ' ';
                }
                for (int j = i + 2; j < n; j++) {
                    cout << arr[j].second + 1 << ' ';
                }
                return;
            } else {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i].second + 1 << ' ';
    }
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while (T--) Solve();
    return 0;
}

/*
찾아야 할 것들
*int 오버플로우, out of bounds
*특수한 경우(n=1?)
*아무것도 하지 않는 대신 무언가를 수행하기. 체계적인 상태를 유지.
*적어두기
*한가지 접근 방식에 얽메이지 말기
*/
// 알고리즘의 작동방식 "완전히" 이해하려 노력하기
// 수행 목표
// 1. "추론"({greedy, D&C, DP, graph}, 증명으로 아이디어)
// 2. 알고리즘 "처음"부터 풀이과정 직접 전개, cutting
// 3. "구현"

/*
take notes.
lower_bound(arr[i] - m)

담당일진 있는 놈들은
먼저 보내야? 뭘 먼저 보내도 학살
담당일진이 학살하던가 자기가 학살하던가
-> 나중에 그 둘을 보내면 된다

큰 수부터 보낸다?
큰 수부터 보내지 않아야 성공하는 경우가 있나?
1 2 3 5 6 7
두 용이 m 보다 작으면 그 두 용은 서로 학살하지 않는다
1. 내가 잡을 수 있는 놈은 내 윗놈들도 잡을 수 있다
2. 윗놈들 다 사라지면 아랫놈들 다 잡을 수 있다
3. 내가 먼저 사라지면 윗놈들이 잡을 수 있는 놈들 다 잡는다
4. 아랫놈들을 먼저 보내면 그쪽으로 처음가는 놈이 학살한다
5. 윗놈들을 보내다가 아랫놈들을 보내고 다시 윗놈들을 보내면?
*/
