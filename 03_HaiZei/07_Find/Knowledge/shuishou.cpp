#include <iostream>
#include <time.h>
using namespace std;

#define min(a, b) ((a) < (b) ? (a) : (b))
double shuishou(double x)
{
    if (x >= 0)
        x -= min(3000, x) * 0.03;
    if (x > 3000)
        x -= (min(x, 12000) - 3000) * 0.1;
    if (x > 12000)
        x -= (min(x, 25000) - 12000) * 0.2;
    if (x > 25000)
        x -= (min(x, 35000) - 25000) * 0.25;
    if (x > 35000)
        x -= (min(x, 55000) - 35000) * 0.3;
    if (x > 5500 0)
        x -= (min(x, 80000) - 55000) * 0.35;
    if (x > 80000)
        x -= (x - 80000) * 0.45;
    return x;
}

#define EXP 1e-2 // 10^(-2)

double binary_algorithm(double y)
{
    double head = 0, tail = 1000000;
    double mid;
    while (tail - head >= EXP)
    {
        mid = (head + tail) / 2.0;
        // printf("[%lf,%lf], mid = %lf , shuishou[%lf]= %lf\n", head, tail, mid, mid, shuishou(mid));
        if (shuishou(mid) == y)
            return mid;
        if (shuishou(mid) < y)
            head = mid;
        else
            tail = mid;
    }
    return head; //两指针重合
}

void test_shui()
{
    double y;
    while (cin >> y)
    {
        if (y < 0)
            break;
        double x = binary_algorithm(y);
        printf("f(%.2lf) = %.2lf\n", x, y);
    }
}

#define MAX_N 10
int main()
{
    srand(time(0));
    test_shui();
    system("pause");
    return 0;
}

