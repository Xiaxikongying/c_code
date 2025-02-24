#include <iostream>
#include <time.h>
using namespace std;

int G_B(int n) //格雷码转自然数   B是自然数   G是格雷码
{
    int ans = 0;
    while (n > 0)
    {
        ans ^= n; //假如一共有m位，每次得到第m，m-1,m-2位的确定值
        n >> 1;
    }
    return ans;
}
/*
Bn = 0 ^ Gn = Gn;【i=n时，i+1位是0】
B(n-1) = Bn ^ G(n-1) = 0 ^ Gn ^ G(n-1) = Gn ^ G(n-1);
B(n-2) = B(n-1) ^ G(n-2) = …… = Gn ^ G(n-1) ^ G(n-2);
…… B0 = B1 ^ G0 = Gn ^ G(n-1) ^ …… ^ G0;


*/
int B_G(int n) //自然数转格雷码   直接与右移一位取异或
{
    return n ^ (n >> 1);
}
int main()
{
    int n;
    
    cin >> n;

    system("pause");
    return 0;
}
uns