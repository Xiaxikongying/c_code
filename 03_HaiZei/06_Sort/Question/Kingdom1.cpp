#include <iostream>
#include <algorithm>
using namespace std;

/*
// haizei oj 256 国王游戏
国王站在队首，有n个大臣，所有人左右手上都有一个数字
每个大臣可以得到的奖赏是他前面所有人左手上的数字乘积 除以 自己 右手 的值（均大于等于1）
但是国王不想给一个大臣太多奖励，请重新排序，让最大值尽可能减小

输入
一个整数 n  和  n+1 行数据
n表示n个大臣，n+1行数据表示国王与n个大臣左右手的数字

输出
一个整数，表示重新排列后的队伍中获奖赏最多的大臣所获得的金币数。
*/

#define MAX_N 1000
int a[MAX_N + 5]; //左手
int b[MAX_N + 5]; //右手
int ind[MAX_N + 5];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) // 1个国王 + n个大臣
    {
        cin >> a[i] >> b[i];
        ind[i] = i;
    }

    //0号位置永远是国王，所以从下标1开始
    sort(ind + 1, ind + n + 1, [&](int i, int j) -> bool
         { return a[i] * b[i] < a[j] * b[j]; });

    int p = a[0];
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (p / b[ind[i]] > ans)
            ans = p / b[ind[i]];
        p *= a[ind[i]];
    }
    cout << ans << endl;

    system("pause");
    return 0;
}