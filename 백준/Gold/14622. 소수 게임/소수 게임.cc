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

bool check[5000000];
bool call[5000000];

void solve() {
    int n;
    cin >> n;
    priority_queue<int> pq[2];
    ll score[2] = {0, 0};
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (!check[a]) {
            if(pq[1].size()<=2){score[1]+=1000;}
            else{
                int c, d;
                c = pq[1].top();
                pq[1].pop();
                d = pq[1].top();
                pq[1].pop();
                score[1] += pq[1].top();
                pq[1].push(c);
                pq[1].push(d);
            }
        } else if (call[a]) {
            score[0]-=1000;
        }else {
            call[a] = true;
            pq[0].push(a);
        }
        if (!check[b]) {
            if(pq[0].size()<=2) score[0]+=1000;
            else{
                int c, d;
                c = pq[0].top();
                pq[0].pop();
                d = pq[0].top();
                pq[0].pop();
                score[0] += pq[0].top();
                pq[0].push(c);
                pq[0].push(d);
            }
        } else if (call[b]){
            score[1]-=1000;
        }else {
            call[b] = true;
            pq[1].push(b);
        }
    }
    if(score[0] > score[1]){
        cout<<"소수의 신 갓대웅\n";
    }else if (score[0] < score[1]){
        cout<<"소수 마스터 갓규성\n";
    }else{
        cout<<"우열을 가릴 수 없음\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    memset(check, true, sizeof(check));
    memset(call, false, sizeof(call));
    check[0] = false;
    check[1] = false;
    for (int i = 2; i * i < 5000000; i++) {
        if (check[i]) {
            for (int j = 2; j * i < 5000000; j++) {
                check[i * j] = false;
            }
        }
    }

    while (t--) solve();
    return 0;
}
