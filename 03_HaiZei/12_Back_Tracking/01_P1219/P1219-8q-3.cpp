#include <iostream>
#include <vector>
using namespace std;

int num = 0;
int vis[15][15] = {0};
vector<vector<string>> solve;

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

void output(int n, vector<string> &queen)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << queen[i][j];
            queen[i][j] = '.';
        }
        cout << endl;
    }
    cout << endl;
}

void dfs(int k, int n, vector<string> &queen)
{
    if (k - 1 == n)
    {
        num++;
        solve.push_back(queen);
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (vis[k][i] == 0)
        {
            addvis(k, i, n);
            queen[k - 1][i - 1] = 'Q';
            dfs(k + 1, n, queen);
            queen[k - 1][i - 1] = '.';
            minusvis(k, i, n);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    string a;
    for (int i = 0; i <= n; i++)
        a.push_back('.');

    vector<string> queen(n, a);

    dfs(1, n, queen);
    cout << num << endl;
    /*
        for (int i = 0; i < num; i++)
        {
            solve[i].erase(solve[i].begin());
            for (int j = 0; j <n ; j++)
            {
                solve[i][j].erase(solve[i][j].begin());
                cout << solve[i][j] << endl;
            }
            cout << endl;
        }

        */

    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << solve[i][j] << endl;
        }
        cout << endl;
    }

    system("pause");
    return 0;
}
