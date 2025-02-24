#include <iostream>
using namespace std;

int add(int a, int b)
{
    int yi, yu;
    do
    {
        yi = a ^ b; // 表示无进位的相加
        yu = a & b; // 表示进位
        yu <<= 1;   // 即双方都是1的情况，这时候需要向前进一位；下一轮循环表示的是--->进位与余数的相加
        a = yi;
        b = yu;
    } while (yu != 0);
    return yi;
}
int add2(int a, int b)
{
    int carry;
    while (b != 0)
    {
        carry = (a & b) << 1; // 计算进位
        a = a ^ b;            // 计算无进位和
        b = carry;            // 将进位赋值给b
    }
    return a;
}

int main()
{
    int a, b;
    int n;
    while (1)
    {
        cin >> a >> b;
        cout << add2(a, b) << endl;
    }
    system("pause");
    return 0;
}