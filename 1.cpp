#include <iostream>
#include <cassert>
using namespace std;

void divide(int a, int b)
{
    // ���� b ��Ϊ 0����ֹ������
    assert(b != 0);
    int result = a / b;
    cout << result << endl;
}

int main()
{
    int x = 10;
    int y = 2;
    divide(x, y); // ����ᴥ������ʧ�ܣ���Ϊ y Ϊ 0
    system("pause");
    return 0;
}
