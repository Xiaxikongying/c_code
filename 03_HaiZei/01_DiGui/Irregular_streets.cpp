#include <iostream>
#include <math.h>
#include <iomanip>
#define S(a) ((a) * (a))
#define LL long long
using namespace std;

// hai zei oj - 239

void f(LL n, LL a, LL &x, LL &y)
{
    if (n == 1)
    {
        if (a == 1)
        {
            x = 0, y = 0;
        }
        else if (a == 2)
        {
            x = 0, y = 1;
        }
        else if (a == 3)
        {
            x = 1, y = 1;
        }
        else
        {
            x = 1, y = 0;
        }
        return;
    }

    LL L = 1LL << (n - 1);
    //求 n级城市的边长  l = pow(2,n-1);
    // 1LL 表示把1转化为longlong类型
    //   1 << n  等同于pow(2,n);

    LL block = L * L;
    // 求 n 级城市一个区域的点数（一个城市分为四个区域）

    LL xx, yy;

    if (a <= block) //表示 a点 在第一区域
    {
        //（x,y）-> (y,x)
        f(n - 1, a, xx, yy);
        x = yy, y = xx;
    }

    else if (a <= 2 * block) //表示 a点 在第二区域
    {
        //（x,y）-> (x,y+l)
        f(n - 1, a - block, xx, yy);
        x = xx, y = yy + L;
    }

    else if (a <= 3 * block) //表示 a点 在第三区域
    {
        //（x,y）-> (x+l,y+l)
        f(n - 1, a - 2 * block, xx, yy);
        x = xx + L, y = yy + L;
    }

    else //表示 a点 在第四区域
    {
        //（x,y）-> (l-y-1,l-x-1)
        f(n - 1, a - 3 * block, xx, yy);
        x = 2 * L - yy - 1, y = L - xx - 1;
    }
    return;
}

int main()
{
    LL t, n, a, b; // n为等级  ab分别为两个点
    cin >> t;
    while (t--)
    {
        cin >> n >> a >> b;
        LL ax, ay, bx, by;
        f(n, a, ax, ay);
        f(n, b, bx, by);
        cout << "a:(" << ax << "," << ay << ")" << endl;
        cout << "b:(" << bx << "," << by << ")" << endl;
        printf("两点距离为：%.0lf\n", 10 * sqrt(pow(ax - bx, 2) + pow(ay - by, 2)));
        //  pow 为n次方  sqrt是平方
    }
    system("pause");
    return 0;
}