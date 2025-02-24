#include <iostream>
using namespace std;

#define MAX_N 100
int n;
int dir[8][2] = {
    {1, 1}, {-1, -1}, {1, 0}, {0, 1}, {1, -1}, {-1, 1}, {-1, 0}, {0, -1}};
char g[MAX_N + 5][MAX_N + 5] = {0};  //存储方阵，但在外围补上0
int vis[MAX_N + 5][MAX_N + 5] = {0}; //一个点只能一次作为开头判断是否可以形成yizhong
int ans[MAX_N + 5][MAX_N + 5] = {0}; //存储是yizhong的元素下标
char match[8] = "yizhong";

void get_ans(int x, int y)
{
    for (int k = 0; k < 8; k++)
    {
        int flag = 1;
        for (int i = 0; match[i]; i++)
        {
            int dx = x + i * dir[k][0];
            int dy = y + i * dir[k][1];
            if (match[i] == g[dx][dy])
                continue;
            flag = 0;
            break;
        }
        if (flag == 1)
        {
            for (int i = 0; match[i]; i++)
            {
                int dx = x + i * dir[k][0];
                int dy = y + i * dir[k][1];
                ans[dx][dy] = 1;
            }
        }
    }
    return;
}

void dfs(int i, int j)
{
    if (g[i][j] == '\0')
        return;
    if (vis[i][j])
        return;
    vis[i][j] = 1;
    if (g[i][j] == 'y')
    {
        get_ans(i, j);
    }
    dfs(i, j + 1);
    dfs(i + 1, j);
    return;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> (g[i] + 1); //将第一行第一列空出来

    dfs(1, 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (ans[i][j])
                cout << g[i][j];
            else
                cout << "*";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}