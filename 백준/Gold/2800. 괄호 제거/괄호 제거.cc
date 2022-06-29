#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int dp[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    cin >> str;
    vector<pair<int, int>> blank;
    stack<int> stk;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            stk.push(i);
        }
        if (str[i] == ')') {
            blank.push_back(make_pair(stk.top(), i));
            stk.pop();
        }
    }
    vector<string> ans;
    for (int i = 0; i < (1 << blank.size()); i++) {
        vector<int> del;
        for (int j = 0; j < blank.size(); j++) {
            if ((i & (1 << j)) != 0) {
                int p, q;
                tie(p, q) = blank[j];
                del.push_back(p);
                del.push_back(q);
            }
        }
        sort(del.begin(), del.end());
        int check = 0;
        int ind = 0;
        string temp;
        while (ind < str.size()) {
            if (check<del.size()&&del[check] == ind) {
                check++;
                ind++;
                continue;
            }
            temp += str[ind++];
        }
        ans.push_back(temp);
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for (int i = 1; i < ans.size(); i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}