#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 计算最短时间使得所有员工到达办公室
long long minTimeToOffice(int n, int k, int p, vector<int> &a, vector<int> &b)
{
    sort(a.begin(), a.end()); // 员工位置排序
    sort(b.begin(), b.end()); // 通行证位置排序

    long long left = 0, right = 1e12;
    while (left < right)
    {
        long long mid = (left + right) / 2;
        int j = 0;

        // 检查当前时间是否可以满足所有员工拿到通行证并到达办公室
        for (int i = 0; i < n && j < k; ++i)
        {
            while (j < k && abs(a[i] - b[j]) + abs(b[j] - p) > mid)
                j++;
            if (j == k)
                break;
            j++;
        }
        if (j < k)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}

int main()
{
    int n, k, p;
    cin >> n >> k >> p; // 读取n, k, p
    vector<int> a(n);   // 员工位置
    vector<int> b(k);   // 通行证位置

    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < k; ++i)
        cin >> b[i];

    // 输出最短时间
    cout << minTimeToOffice(n, k, p, a, b) << endl;
    system("pause");
    return 0;
}
