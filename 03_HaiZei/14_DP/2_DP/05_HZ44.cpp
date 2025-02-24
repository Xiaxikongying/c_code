#include <iostream>
#include <algorithm>
using namespace std;

/*
最长上升子序列
10
3 2 5 7 4 5 7 9 6 8
5
*/
#define Max 1000000
int dp[Max + 5] = {0};
// dp[i]表示以val[i]结尾的序列 最长上升子串长度是多少
int val[Max + 5] = {0}; //存放输入序列
int pre[Max + 5] = {0};
// pre[i] = j  表示 下标i的前一位是下标j---->val[i] 前一为是  val[j]

int main()
{
    val[0] = -1; //为了确保单独的一个也可以dp值为1
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> val[i];

    int m = -1, ind;
    for (int i = 1; i <= n; i++) //遍历每一个数
    {
        for (int j = 0; j < i; j++)//遍历i前面的数字，找的比i小的值，在其dp上+1
        {
            if (val[j] < val[i])
            {
                if (dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                    pre[i] = j;
                }
            }
        }
        if (dp[i] > m)
        {
            ind = i;
            m = dp[i];
        }
    }

    cout << m << endl;
    cout << val[ind] << " ";
    while (pre[ind] != 0)
    {
        cout << val[pre[ind]] << " ";
        ind = pre[ind];
    }
    cout << endl;
    system("pause");
    return 0;
}
