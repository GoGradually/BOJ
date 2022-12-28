#include <iostream>
#include <algorithm> // min
#include <math.h>
#include <string>
#include <vector>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0);  // scanf 안쓸 경우 쓰세요. Cin 사용시
    int n; cin >> n;
 
    int count = 0;
    int cand[3] = { 0, };
 
    for (int i = 1; i <= n; i++) {
        if (i > 0 && i < 100) {
            count++;
        }
        else if(i == 1000){
            break;
        }
        else {
            int cand2 = i;
            for (int j = 0; j < 3; j++) {
                cand[j] = cand2 % 10;
                cand2 = cand2 / 10;
            }
 
            if (cand[0] - cand[1] == cand[1] - cand[2])
                count++;
        }
    }
    cout << count << "\n";
 
    return 0;
}