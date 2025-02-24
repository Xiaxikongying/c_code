#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> h(n), d(n);
    for (int i = 0; i < n; ++i)
        cin >> h[i];

    // 用于存储地块高度的有序列表
    set<int> s;
    // 从右向左遍历
    for (int i = n - 1; i >= 0; --i)
    {
        // 查找第一个比 h[i] 大的元素
        auto it = s.upper_bound(h[i]);
        if (it == s.end())
            d[i] = -1;
        else
            d[i] = *it;
        // 将当前高度插入到有序集合中
        s.insert(h[i]);
    }
    for (int i = 0; i < n; ++i)
        printf("%d ", d[i]);
    printf("\n");
    system("pause");
    return 0;
}

/*
野猪骑士最近在一条路上锻炼，整条路可以被分作n块地块，每个地块有自己的高度hi,i∈{1,2,3,...,n}。野猪骑士在地块i时，会跳向 下标比i大 且 高度比hi严格大的地块的集合中，高度最小的地块。
野猪骑士希望知道自己在每个地块上的下一跳的目的地的高度，如果下一跳不存在的话，则记为-1。
更形式化地说，给定一个数列h,求一个数列d，其中如果{hj | j > i & hj > hi}≠∅,则di := min{hj | j > i & hj > hi}，否则di := -1(其中:=是赋值符号)。
输入描述：
第一行包括一个正整数n，第二行包含n个正整数h1，h2,...,hn。
输出描述：
一行，包括n个正整数d1，d2,...，dn。
补充说明：
3≤n≤1e5, 1<h<1e9
由于本题输出较多，C++使用printf，否则容易超时。

测试数据1:
输入：
4
4 1 2 3
输出：
-1 2 3 -1

测试数据2:
输入：
7
11 13 10 5 12 21 3
输出：
12 21 12 12 21 -1 -1
*/