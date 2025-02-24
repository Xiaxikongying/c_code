#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct Product
{
    int p; // 利润
    int d; // 保质期
};

bool compare(Product &a, Product &b)
{
    return a.d < b.d; // 按日期从大到小排序
}

int main()
{
    int N;
    while (cin >> N)
    {
        vector<Product> ords(N);
        for (int i = 0; i < N; ++i)
            cin >> ords[i].p >> ords[i].d;

        // 按照利润从大到小排序
        sort(ords.begin(), ords.end(), compare);
        // 用优先队列存储能卖出的商品利润
        priority_queue<int, greater<int>> q; // 小顶堆
        int to_p = 0;
        for (int i = 0; i < N; ++i)
        {
            if (q.size() < ords[i].d) // 日期充足 直接入队
            {
                q.push(ords[i].p);
                to_p += ords[i].p;
            }
            else if (!q.empty() && q.top() < ords[i].p)
            {
                to_p += ords[i].p - q.top();
                q.pop();
                q.push(ords[i].p);
            }
        }
        cout << to_p << endl;
    }
    system("pause");
    return 0;
}

/*
Quinn有太多的外卖订单要做。每项订单花费一个单位时间。Quinn从0时刻开始工作，将持续工作1e9个单位时间。在任一时刻，Quinn都可以选择编号1到N的N(1≤N≤1*10^5)项订单中的任意一项订单来完成。Quinn在每个单位时间里只能做1个订单，而每项订单又有一个截止日期。所以Quinn可能不得不放弃部分订单。对于第i个订单，有一个截止时间Di(1≤Di≤10^9)，如果Quinn可以完成这个订单，那么她可以获利Pi(1≤P≤10^9)。Quinn希望最大化利润，但这对她来说太难了，于是她来找你帮忙。
输入描述
第1行包含一个整数N
第2行到第N+1行，每行包含两个以空格分隔的整数Di和Pi
符号含义参照题目描述。
输出描述
一行，包含一个整数，表示Quinn所能达到的利润最大值

测试数据1:
输入：
3
2 10
1 5
1 7
输出：
17
说明：
Complete job 3(1,7) at time 1 and complete job 1(2,10) at time 2 to maximize the earnings(7 + 10 -> 17).
*/