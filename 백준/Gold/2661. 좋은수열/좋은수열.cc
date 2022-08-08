#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <cmath>
#include <climits>
#include <unordered_map>
#include <stack>
using namespace std;
typedef long long ll;

int n;
bool flag = false;
bool check(string s, int count)
{
    int i;
    for (i = 1; i <= s.length() / 2; i++)
    {
        if (s.substr(s.length() - i, count) == s.substr(s.length() - (i * 2), count))
        {
            return false;
        }
        else count++;
    }
    return true;
}
void goodse(string s)
{
    if (flag)return;
    int j = 1;

    if (s.length() == n)
    {
        if (flag == false)
        {
            flag = true;
            cout << s; return;
        }
        else return;
    }
    for (j = 1; j <= 3; j++)
    {
        if (check(s + (char)(j + '0'), 1) == true)
        {
            goodse(s + (char)(j + '0'));

        }
    }

}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    string s = "1";
    goodse(s);
    return 0;
}




