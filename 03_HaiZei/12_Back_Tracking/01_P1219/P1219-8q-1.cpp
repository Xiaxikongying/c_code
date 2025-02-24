#include <iostream>
#include <vector>
using namespace std;

int num = 0;
int vis[15][15] = {0};
vector<int> a;
vector<vector<int>> b;

void addvis(int i, int j, int n)
{
    for (int a = 1; a <= n; a++)
    {
        vis[i][a]++;
        vis[a][j]++;
    }
    int a = i, b = j;
    while (a <= n && b <= n)
        vis[a++][b++]++;

    a = i, b = j;
    while (a >= 1 && b >= 1)
        vis[a--][b--]++;

    a = i, b = j;
    while (a >= 1 && b <= n)
        vis[a--][b++]++;

    a = i, b = j;
    while (a <= n && b >= 1)
        vis[a++][b--]++;
}

void minusvis(int i, int j, int n)
{
    for (int a = 1; a <= n; a++)
    {
        vis[i][a]--;
        vis[a][j]--;
    }

    int a = i, b = j;
    while (a <= n && b <= n)
        vis[a++][b++]--;

    a = i, b = j;
    while (a >= 1 && b >= 1)
        vis[a--][b--]--;

    a = i, b = j;
    while (a >= 1 && b <= n)
        vis[a--][b++]--;

    a = i, b = j;
    while (a <= n && b >= 1)
        vis[a++][b--]--;
}

void dfs(int k, int n)
{
    if (k - 1 == n)
    {
        num++;
        b.push_back(a);
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (vis[k][i] == 0)
        {
            addvis(k, i, n);
            a.push_back(i);
            dfs(k + 1, n);
            a.pop_back();
            minusvis(k, i, n);
        }
    }
}

int main()
{
    //  n必须大于等于6  这样才会有3个解
    int n;
    cin >> n;
    dfs(1, n);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < n; j++)
            cout << b[i][j] << " ";
        cout << endl;
    }
    cout << num << endl;
    system("pause");
    return 0;
}