#include <iostream>
using namespace std;
#define MAX 20
int s[4];                 //一共4个科目   每个科目的题目数量
int question[4][MAX + 2]; //每个题目花费的时间
int ans;                  //每科 最短时间
/*
1 2 1 3
5
4 3
6
2 4 3

20
*/
void dfs(int ind, int cnt, int l, int r) // ind表示科目的下标  cnt表示第几道题目  lr表示左右脑思考的时间
{
    if (cnt == s[ind])
    {
        if (ans > max(l, r))
            ans = max(l, r);
        return;
    }
    dfs(ind, cnt + 1, l + question[ind][cnt], r);
    dfs(ind, cnt + 1, l, r + question[ind][cnt]);
    return;
}

int main()
{
    for (int i = 0; i < 4; i++)
        cin >> s[i];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < s[i]; j++)
            cin >> question[i][j];
    }

    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        ans = 1500;
        dfs(i, 0, 0, 0);
        sum += ans;
    }
    cout << sum << endl;

    system("pause");
    return 0;
}
/*
int solve(int k)
{
    int ans = MAX_NUM;
    int T = (1 << s[k]); //若有4题   T = 10000(二进制)-->16
    cout << T << endl;
    for (int i = 0; i < T; i++) // j 的取值为 0001---1111
    {
        int j = i, l = 0, r = 0;
        while (j)
        {
            l += t[k][ ind[j & -j] ]; //将为1的放入左边
            j -= (j & -j);              //放入后消除标记
        }

        // 0001 0010  0011 0100 0101 0110 0111 1000 1001.....1111
        // 1表示取该题目放在左边   0表示放在右边

        r = sum【k】 - l; //右边 = 总值 - 左边
        ans = min(ans, max(l, r));
    }
    return ans;
}
*/
