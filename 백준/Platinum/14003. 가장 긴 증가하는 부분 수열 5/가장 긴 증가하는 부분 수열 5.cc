#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n); // 수열 A
    vector<int> d(n); // d[i]: i번째 원소를 마지막으로 하는 LIS의 길이
    vector<int> v; // LIS의 원소를 저장하는 벡터

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        if (v.empty() || v.back() < a[i]) { // LIS의 마지막 원소보다 큰 경우
            v.push_back(a[i]);
            d[i] = v.size();
        } else { // 이분 탐색을 사용하여 LIS에 삽입할 위치를 찾음
            auto it = lower_bound(v.begin(), v.end(), a[i]);
            *it = a[i];
            d[i] = it - v.begin() + 1;
        }
    }

    // 가장 긴 증가하는 부분 수열의 길이
    int len = v.size();

    // 가장 긴 증가하는 부분 수열 출력
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--) {
        if (d[i] == len) {
            ans.push_back(a[i]);
            len--;
        }
    }
    reverse(ans.begin(), ans.end());

    cout << v.size() << '\n';
    for (int x : ans) {
        cout << x << ' ';
    }

    return 0;
}
