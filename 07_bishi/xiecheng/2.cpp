#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 函数实现操作以求出剩余最少数字的数量
int minimizeres(vector<int> &a, int n, int m, int k)
{
    // 对集合排序
    sort(a.begin(), a.end());

    // 初始化剩余数量
    int left = 0; // 滑动窗口的左指针
    int res = n;  // 初始化剩余数量为总数

    // 遍历数组，通过右指针控制窗口的大小
    for (int right = 0; right < n; ++right)
    {
        // 判断当前窗口的最大值和最小值是否符合条件
        while (left < right && a[right] - a[left] > k)
        {
            left++; // 如果不符合条件，左指针右移
        }

        // 当窗口大小足够时，可以执行操作
        if (right - left + 1 >= m)
        {
            res--;  // 每次操作删除一个元素，即最小值
            left++; // 删除最小值后，窗口左指针右移
        }
    }
    return res; // 返回剩余的元素数量
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k; // 读取n, m, k
    vector<int> a(n);   // 初始化数组

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i]; // 读取集合中的元素
    }

    // 输出操作后剩余的最少数量
    cout << minimizeres(a, n, m, k) << endl;
    system("pause");
    return 0;
}
