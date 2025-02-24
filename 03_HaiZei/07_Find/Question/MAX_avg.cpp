/*
给定一个有 N个元素的非负序列，
求长度大于等于  M的连续子序列 的最大平均值。
输入
第一行输入两个数N,M。 (1 < N M<100000)接下来 N 行，每行输入一个数表示非负序列。
输出
输出一个整数表示最大平均值乘 1000 的结果
10 6
6 4 2 10 3 8 5 9 4 1

6500
haizei oj 242
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 100000
long long a[MAX_N + 5], b[MAX_N + 5];

int check(long long *a, int n, int M, int A)
{
    //判定 是否存在 大于 A 的平均值
    b[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        //将a数组全部减A存入b中   并且变成 前缀和数组
        b[i] = a[i] - A;
        b[i] += b[i - 1];
    }

    long long pre = 0;
    for (int i = M; i <= n; i++)
    {
        pre = min(pre, b[i - M]); //寻找最小前缀和
        if (b[i] - pre >= 0)      //若存在b[i] 减去最小前缀和 大于 0 则存在平均值A
            return 1;
    }
    return 0;
}

int slove(long long *a, int n, int M, int max_num)
{                                      //  数组 a    长度n   想要的长度 m  最大平均值 max
    int head = 0, tail = max_num, mid; //二分法 搜索的范围  0--max
    while (head < tail)
    {
        mid = (head + tail + 1) / 2;
        if (check(a, n, M, mid) == 1) //若有m的长度平均值大于mid
            head = mid;
        else
            tail = mid - 1;
    }
    return head;
    // head 与 tail重合
}

int main()
{
    int n, m, max_num;
    scanf("%d%d", &n, &m);
    for (int i = 1, x; i <= n; i++)
    {
        scanf("%d", &x);
        x *= 1000;
        a[i] = x;
        max_num = max(max_num, x);
    }

    printf("%d\n", slove(a, n, m, max_num));
    system("pause");
    return 0;
}
