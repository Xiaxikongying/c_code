#include <iostream>
#include <math.h>
using namespace std;

int calc(string &s, int l, int r)
{
    int pri = 999;
    int cur_pri = 1000;
    int temp_pri = 0;
    int pos = -1;
    for (int i = l; i < r; ++i)
    {
        cur_pri = 1000;
        switch (s[i])
        {
        case '(':
            temp_pri += 100;
            break;
        case ')':
            temp_pri -= 100;
            break;
        case '+':
        case '-':
            cur_pri = temp_pri + 1;
            break;
        case '*':
        case '/':
            cur_pri = temp_pri + 2;
            break;
        case '^':
            cur_pri = temp_pri + 3;
            break;
        }

        if (pri >= cur_pri) // 寻找优先级最低的符号 一定要有=号，相同优先级 先运算前面的符号
        {
            pos = i;
            pri = cur_pri;
        }
    }
    if (pos == -1) // 没有符号了
    {
        int num = 0;
        for (int i = l; i < r; ++i)
        {
            if (isdigit(s[i]))
                num = num * 10 + (s[i] - '0');
        }
        return num;
    }
    else // 还有符号
    {
        int a = calc(s, l, pos);
        int b = calc(s, pos + 1, r);

        switch (s[pos])
        {

        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '^':
            return pow(a, b);
        }
    }
    return 0;
}

int main()
{
    string str;
    while (cin >> str)
    {
        // 输入表达式
        cout << calc(str, 0, str.size()) << endl;
    }

    system("pause");
    return 0;
}