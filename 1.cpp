#include <iostream>
#include <cassert>
using namespace std;

void divide(int a, int b)
{
    // 断言 b 不为 0，防止除以零
    assert(b != 0);
    int result = a / b;
    cout << result << endl;
}

int main()
{
    int x = 10;
    int y = 2;
    divide(x, y); // 这里会触发断言失败，因为 y 为 0
    system("pause");
    return 0;
}
