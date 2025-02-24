#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

//------------hai zei oj 263
/*
有 n列火车按 1 1 到 n的顺序从东方左转进站，这个车站是南北方向的，
它虽然无限长，车只能倒着从西方出去，而且每列火车必须进站，先进后出。

进站的火车编号顺序为 1∼n

现在请你按火车编号从小到大的顺序，输出前 20种可能的出站方案。
3
123
132
213
231
321
//------没有 3 1 2  若3出栈  1 2 必定已经入栈
//则只有 3 2 1一种
*/

bool isValid(int a[], int n)
{
    stack<int> s;
    int x = 1;
    for (int i = 0; i < n; i++)
    {
        if (s.empty() || s.top() < a[i])
        {
            while (x <= a[i])
            {
                s.push(x);
                x++;
            }
        }

        if (s.top() != a[i])
        {
            return false;
        }
        s.pop();
    }
    return true;
}

int main()
{
    int n, count = 20;
    cin >> n;
    int a[22];

    for (int i = 0; i < n; i++)
        a[i] = i + 1;

    do
    {
        if (isValid(a, n))
        {
            for (int i = 0; i < n; i++)
            {
                cout << a[i];
            }
            cout << endl;
            count--;
        }
    } while (next_permutation(a, a + n) && count); // 求 a 到 a+n 这段的全排列

    system("pause");
    return 0;
}
