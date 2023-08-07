#include <bits/stdc++.h>
#define ll long long
#define INF 1e9 + 10
#define lINF 1e18 + 10LL
const ll MOD = 1000000007LL;
// #include <atcoder/modint.hpp>
// using mint = atcoder::modint998244353;

using namespace std;

ll arr[100000];
ll n, m;

bool check(ll mid) {
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += mid / arr[i];
        if (cnt >= m) return true;
    }
    return false;
}

ll first_true(ll lo, ll hi) {
    hi++;
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}

void Solve() {
    cin >> n >> m;
    ll mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }
    ll left = 1;
    ll right = mx*m;
    cout << first_true(left, right) << '\n';
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
*아무것도 하지 않는 대신 무언가를 수행하고 체계적인 상태를 유지
*적어두기
*한가지 접근 방식에 얽메이지 말기
*/
// 문제의 "맥" 잡고있기, 알고리즘의 작동방식 "완전히" 이해하려 노력하기
//"추론"(증명)