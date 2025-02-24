#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 50000
/*
5
1 10
2 4
3 6
5 8
4 7

4
1 2 3 2 4
*/
//挤奶
struct Data
{
    int begin, end, id;
} arr[MAX];

bool cmp(const Data &a, const Data &b)
{
    if (a.begin != b.begin)
        return a.begin < b.begin;
    return a.id < b.id;
}

int n;

int main()
{
    scanf("%d", &n);//奶牛的数量
    vector<int> ind(n);
    vector<int> vis(n);
    //输入奶牛 挤奶的开始时间  结果时间
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &arr[i].begin, &arr[i].end);
        arr[i].id = i;
    }
    //根据开始时间排序
    sort(arr, arr + n, cmp);

    int cnt = 1;//一共用到了几台机器
    ind[arr[0].id] = cnt;//arr[0].id正在使用第cnt台机器
    int now = arr[0].begin;//现在的时间
    bool flag;
    for (int i = 1; i < n; i++)
    {
        flag = true;
        now = arr[i].begin;
        //该循环是判断前面的奶牛是否有已经用完的机器
        for (int j = 0; j < i; j++)
        {
            if (now > arr[j].end && vis[j] != 1)
            {
                vis[i] = 1;//表示它的机器转给其他奶牛了
                arr[j].end = arr[i].end;
                /*
                此处为什么是将后面的i设为禁用，并将j的结束时间设置为i的？
                这是因为题中表示 当有多台机器同时空闲时，优先使用编号小的
                而第一次使用的（即开头的机器排序是从小到大的）
                这样就可以保证符合题意
                */
                flag = false;
                ind[arr[i].id] = ind[arr[j].id];//转变机器的使用者
                break;
            }
        }
        if (flag)//机器不够，添加一台
            ind[arr[i].id] = (++cnt);
    }

    printf("%d\n", cnt);
    for (int i = 0; i < n; i++)
        printf("%d\n", ind[i]);
    system("pause");
    return 0;
}
