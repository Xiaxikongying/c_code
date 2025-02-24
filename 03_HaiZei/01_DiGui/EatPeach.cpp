#include <iostream>
using namespace std;
/*路飞买了一堆桃子不知道个数，第一天吃了一半的桃子，还不过瘾，又多吃了一个。以后他每天吃剩下的桃子的一半还多一个，
到 n天只剩下一个桃子了。路飞想知道一开始买了多少桃子
 */

int eat(int n)
{

    if (n == 1)
        return 1;

    else
    {
        return (eat(n - 1) + 1) * 2;
    }
}

int main()
{
    int n;
    cin >> n;
    cout << eat(n) << endl;
    system("pause");
    return 0;
}