#include <iostream>
#include <queue>
using namespace std;
#define MAX 20

int n, ans = 0;
string s[MAX + 2];
string start;
int d[MAX + 2][MAX + 2]; //用于存储每两个单词的重叠部分
int vis[MAX];

int coincide(string &s1, string &s2) //得到两个单词最短的重叠部分
{
    for (int i = s1.size() - 1; i >= 1; i--) //表示s1后i个单词
    {
        bool flag = true;
        for (int j = 0; j < s1.size() - i; j++) //表示s2前i个单词
        {
            if (s1[i + j] == s2[j])
                continue;
            flag = false;
            break;
        }
        if (s1.size() - i == s2.size())
            return 0;
        if (flag)
            return s1.size() - i;
    }
    return 0;
}

void dfs(int x, int L) // x表示最后一个单词的下标   L表示龙的长度
{
    if (L > ans)
        ans = L;
    for (int y = 0; y < n; y++)
    {
        if (d[x][y] == 0 || vis[y] == 2) //没有重叠 或 已经使用过两次
            continue;
        vis[y] += 1;
        dfs(y, L + s[y].size() - d[x][y]);
        vis[y] -= 1;
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    cin >> start;
    //初始化d[][]数组
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            d[i][j] = coincide(s[i], s[j]);
    }

    for (int i = 0; i < n; i++)
    {
        if (s[i][0] != start[0]) //寻找一个龙头
            continue;
        vis[i] += 1;
        dfs(i, s[i].size());
    }
    cout << ans << endl;

    system("pause");
    return 0;
}
