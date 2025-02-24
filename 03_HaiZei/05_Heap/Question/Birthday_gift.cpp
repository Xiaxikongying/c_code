#include <iostream>
#include <set>
#include <vector>
using namespace std;

/*
输入n m
n为 n个数
m表示 可以选择 m个 连续的部分
求m个连续部分和 的最大值
各个部分不可以重复

输入
5 2
2 -3 2 -1 2
输出
5
*/

#define MAX_N 100000
long long arr[MAX_N + 5] = {0};
int l[MAX_N + 5] = {0};  //前一位
int r[MAX_N + 5] = {0};  //后一位
int st[MAX_N + 5] = {0}; //是否存在
typedef pair<int, int> PII;
set<PII> h;

void del(int x)
{
    r[l[x]] = r[x]; // x的前一位节点 向后指向x的后一位节点
    l[r[x]] = l[x]; // x的后一位节点 向前指向x的前一位节点
    st[x] = 1;
    return;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    scanf("%lld", arr + 1);
    int k = 1;
    for (int i = 1, a; i < n; i++)
    {
        scanf("%d", &a);
        // 1LL会在运算时把后面的临时数据扩容成long long类型，再在赋值给左边时转回int类型。
        if (1LL * arr[k] * a < 0) //上一个数据与异号
            arr[++k] = a;
        else
            arr[k] += a; //同号就合并
    }
    //至此 arr变为正负交替的序列

    n = k;
    long long cnt = 0, s = 0;
    // cnt 为正数个数，s是和
    for (int i = 1; i <= n; i++)
    { //将arr变为双向链表  初始化
        if (arr[i] > 0)
        {
            cnt++;
            s += arr[i]; //所有正数的和值
        }
        h.insert(PII(abs(arr[i]), i));
        l[i] = i - 1;
        r[i] = i + 1;
    }

    while (cnt > m)
    {
        while (st[h.begin()->second]) //查看是否被删除
            h.erase(h.begin());

        int ind = h.begin()->second;
        h.erase(h.begin());

        int left = l[ind], right = r[ind];
        if ((left > 0 && right <= n) || arr[ind] > 0)
        {
            s -= abs(arr[ind]);
            cnt -= 1;
            arr[ind] += arr[left] + arr[right];
            h.insert(PII(abs(arr[ind]), ind));
            del(left);
            del(right);
        }
    }
    printf("%lld\n", s);

    system("pause");
    return 0;
}