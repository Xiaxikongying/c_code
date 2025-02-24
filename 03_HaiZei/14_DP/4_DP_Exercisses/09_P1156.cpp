#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 100
struct Data
{
    int t, f, h;
} arr[MAX_N + 5];
int dp[2 * MAX_N + 5];

bool cmp(const Data &a, const Data &b)
{
    return a.t < b.t;
}

int main()
{
    int D, G; //井的高度  垃圾数量
    cin >> D >> G;
    for (int i = 1; i <= G; i++) // t垃圾投入的时间  f可增加的HP，h可增加的高度
        cin >> arr[i].t >> arr[i].f >> arr[i].h;
    sort(arr + 1, arr + G + 1, cmp);

    dp[0] = 10;                  //初始生命值为10
    for (int i = 1; i <= G; i++) //遍历i个物品
    {
        for (int j = D; j >= 0; j--) //遍历高度
        {
            if (dp[j] < arr[i].t) //前i-1件物品  HP不能支撑等到第i件
                continue;
            if (arr[i].h + j >= D) //可以跳出井
            {
                cout << arr[i].t << endl;
                system("pause");
                return 0;
            }

            //将第i件堆起来
            dp[j + arr[i].h] = max(dp[j + arr[i].h], dp[j]);
            //吃掉第i个
            dp[j] += arr[i].f;
        }
    }
    cout << dp[0] << endl;
    system("pause");
    return 0;
}