/*题目描述
输入N 组数据，对每组数据输出逆序对个数)对于每测试用例，第一行输入此组数据元素个数，接下来行，每行一个数，表示元素。
(1 <x < 500000)当读入的元素个数x为零时，程序结束输出,对于每组测试用例，输出一个数，表示逆序对个数
输入
5
9 1 0 5 4

3
1 2 3

0
输出
6 0
*/
// haizei oj 248

#include <iostream>
using namespace std;

#define Max_n 500000
int arr[Max_n + 5];
int temp[Max_n + 5];

long long merge_sort(int *arr, int l, int r)
{
    if (r - l <= 1)
        return 0;
    int mid = (r + l) / 2;
    long long a = merge_sort(arr, l, mid);
    long long b = merge_sort(arr, mid, r);

    long long c = 0;
    int p1 = l, p2 = mid, k = 0;
    while (p1 < mid || p2 < r)
    {
        if (p2 == r || (p1 < mid && arr[p1] <= arr[p2]))
            temp[k++] = arr[p1++];
        else
        {
            temp[k++] = arr[p2++];
            c += (mid - p1);
        }
    }
    for (int i = l; i < r; i++)
        arr[i] = temp[i - l];
    return a + b + c;
}
int main()
{
    int n;
    while (1)
    {
        scanf("%d", &n);
        if (n == 0)
            break;

        for (int i = 0; i < n; i++)
            scanf("%d", arr + i);
        printf("%lld\n", merge_sort(arr, 0, n));
    }
    system("pause");
    return 0;
}