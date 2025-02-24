#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    string b1, b2;
    cin >> b1 >> b2;

    int minL = n + m;

    // 遍历第二块积木相对于第一块积木的所有可能的对齐方式
    for (int offset = -m + 1; offset < n; ++offset)
    {
        bool valid = true;
        int start = max(0, offset);
        int end = min(n, m + offset);

        for (int i = start; i < end; ++i)
        {
            if ((b1[i] - '0') + (b2[i - offset] - '0') > 3)
            {
                valid = false;
                break;
            }
        }

        if (valid)
        {
            int curL = max(n, m + offset) - min(0, offset);
            minL = min(minL, curL);
        }
    }

    cout << minL << endl;
    system("pause");
    return 0;
}

/*
牛牛有一种锯齿状的积木，这种积木比较长，但是每个单位长度的高度是相等的，高度为1或者2。
现在牛牛拿出了两块长度分别为n和m的积木，她现在想把这两块积木拼接在一起，即使中间有空隙也没有关系。
但是拼接后的积木的高度要不超过3，请你帮助牛牛计算在满足这个前提下拼接后的积木的长度最短可以是多少。
输入描述
第一行给出两个正整数n，m，代表第一块和第二块积木的长度
第二行给出n个数字代表第一块积木每个单位的高度
第三行给出m个数字代表第二块积木每个单位的高度
1 ≤n,m≤1000
输出描述
在一行中输出一个正整数代表拼接后积木的最短长度
示例1
输入
7  10
2212112
2112112112
输出
10

示例二
示例2
输入
3 2
222
22
输出
5
*/