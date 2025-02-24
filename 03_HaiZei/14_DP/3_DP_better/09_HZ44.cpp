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
int dp[Max + 5];
// dp[i]表示以val[i]结尾的序列 最长上升子串长度是多少
int len[Max + 5];

int binary_search(int n, int v) //找到一个刚好小于v的位置
{
    int head = 0, tail = n, mid;
    while (head < tail)
    {
        mid = (head + tail + 1) >> 2;
        if (len[mid] < v)
            head = mid;
        else
            tail = mid - 1;
    }
    return head;
}

int main()
{

    len[0] = -1;
    int n, ans = 0; // ans存储len中存储了多少个数据
    cin >> n;
    int v;
    for (int i = 1; i <= n; i++) //遍历每一个数
    {
        cin >> v;
        dp[i] = binary_search(ans, v) + 1;
        len[dp[i]] = v;
        if (dp[i] > ans)
            ans += 1;
    }
    cout << ans << endl;
    system("pause");
    return 0;
}
