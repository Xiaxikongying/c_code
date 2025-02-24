#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

/*hai zei oj 838
有三个升序队列q1,q2,q3，每个队列都有若干升序个整数(至少有一个)
现在分别在每个序列中选择一个数 a b c,而D = |a-b| + |b-c| + |a-c|
求最小值D

*/

int min_num(int a, int b, int c)
{
    if (a > b)
        swap(a, b);
    if (a > c)
        swap(a, c);
    return a;
}

int MinD(queue<int> que1, queue<int> que2, queue<int> que3)
{
    int ans = 1000000;
    while (!que1.empty() && !que2.empty() && !que3.empty())
    {
        int a = que1.front();
        int b = que2.front();
        int c = que3.front();
        int temp = abs(a - b) + abs(a - c) + abs(b - c);

        if (temp < ans)
            ans = temp;

        int mi = min_num(a, b, c);
        if (a == mi)
            que1.pop();
        if (b == mi)
            que2.pop();
        if (c == mi)
            que3.pop();
    }
    return ans;
}

int main()
{
    int m, n, k, x;
    queue<int> que1, que2, que3;
    cin >> m >> n >> k;
    for (int i = 0; i < m; i++)
    {
        cin >> x;
        que1.push(x);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        que2.push(x);
    }
    for (int i = 0; i < k; i++)
    {
        cin >> x;
        que3.push(x);
    }
    cout << func(que1, que2, que3) << endl;
    //system("pause");
    return 0;
}

/*
3 4 5           m n k  
1 2 3           que1
4 5 6 7         que2
8 9 10 11 12    que3

10
*/