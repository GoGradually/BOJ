#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> g[100000];
bool check[100000];
vector<int> arr;
vector<int> dfsArr;
int order[100000];

int assist(int a, int b)
{
    return order[a] < order[b];
}

void dfs(int x)
{
    if (check[x] == true)
    {
        return;
    }
    check[x] = true;
    dfsArr.push_back(x);
    for (int y : g[x])
    {
        if (check[y] == false)
        {
            dfs(y);
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        temp--;
        arr.push_back(temp);
        order[arr[i]] = i;
    }
    for (int i = 0; i < n; i++)
    {
        sort(g[i].begin(), g[i].end(), assist);
    }
    dfs(0);
    if (dfsArr == arr)
    {
        cout << 1 << '\n';
    }
    else
    {
        cout << 0 << '\n';
    }
    return 0;
}