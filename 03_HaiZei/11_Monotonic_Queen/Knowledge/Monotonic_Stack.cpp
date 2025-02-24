#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void output(vector<int> &arr)
{
    int n = arr.size();
    int len = 0;
    for (int i = 0; i < n; i++)
        len += printf("%3d", i);
    printf("\n");

    for (int i = 0; i < len; i++)
        printf("-");
    printf("\n");

    for (int i = 0; i < n; i++)
        printf("%3d", arr[i]);
    printf("\n");

    return;
}
/*
10 4
7 8 5 6 2 3 4 1 10 9
*/
int main()
{
    int n; //序列的长度
    cin >> n;
    vector<int> arr(n + 2, -1);
    stack<int> s; //双端队列
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    output(arr);
    vector<int> l(n + 2);
    vector<int> r(n + 2);
    //right   从左向右遍历（找最近 较小值）
    for (int i = 0; i < arr.size(); i++)
    {
        while (!s.empty() && arr[s.top()] > arr[i])
        {
            r[s.top()] = i; //是下标为 i的值把下标为top的值弹出
            s.pop();
        }
        s.push(i); //压入的值的下标
    }
    //清空栈
    while (!s.empty())
        s.pop();
    //left  右向左遍历（找最近 较小值）
    for (int i = arr.size(); i >= 0; i--)
    {
        while (!s.empty() && arr[s.top()] > arr[i])
        {
            l[s.top()] = i;
            s.pop();
        }
        s.push(i); //压入的值的下标
    }
    for (int i = 1; i <= n; i++)
    {
        printf("arr[%d] = %d,  left:[%d] = %d,   right:[%d] = %d\n",
               i, arr[i], l[i], arr[l[i]], r[i], arr[r[i]]);
    }
    system("pause");
    return 0;
}
/*
10
7 8 5 6 2 3 4 1 10 9
*/