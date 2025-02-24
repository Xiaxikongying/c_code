#include <iostream>
#include <deque>
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
    int k; //窗口的长度
    cin >> n >> k;
    vector<int> arr(10);
    deque<int> q; //双端队列
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    output(arr);

    for (int i = 0; i < n; i++)
    {
        while (!q.empty() && arr[q.back()] > arr[i]) //若插入的元素小于 队尾元素  队尾元素出队
            q.pop_back();
        q.push_back(i); //压入的值的下标

        if (i - q.front() == k) //维护窗口大小  超出窗口大小
            q.pop_front();
        printf("[%d, %d] = arr[%d] = %d\n", max(i - k + 1, 0), i, q.front(), arr[q.front()]);
        //arr [i-k , i]区间内的最小值 k为窗口大小
    }

    system("pause");
    return 0;
}