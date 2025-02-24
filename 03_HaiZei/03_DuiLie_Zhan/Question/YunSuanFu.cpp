#include <iostream>
#include <math.h>
using namespace std;

// hai zei oj 266
/*
​给出一个表达式,其中运算符仅包含 +,-,*,/,^ 要求求出表达式的最终值。

(2+2)^(3-1)/2
8

*/

bool is_operator(char c)
{
    switch (c)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
        return true;
    default:
        return false;
    }
    return false;
}
//判断一个char是不是运算符
int calc(string &s, int l, int r)
{
    int pos = -1;     //找到优先级最低符号的位子  即 最后运算的符号
    int pri = 9999;   // pri 致力于找到最低的优先级
    int cur_pri;      //符号的优先级
    int temp_pri = 0; //额外的优先级（）
    for (int i = l; i < r; i++)
    {
        cur_pri = 10000;
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

        if ((s[i] == '-' || s[i] == '+') && (i - 1 < 0 || is_operator(s[i - 1])))
        { //  确定 s[i] 是正(负)号    并且   正负号在最左边  或者 在另外一个运算符的旁边
            cur_pri += 1000;
        }

        if (pri >= cur_pri) //寻找优先级最低的符号位置
        {
            pri = cur_pri;
            pos = i;
        }
    }
    if (pos == -1) //表达式中没有运算符
    {
        int num = 0;
        for (int i = l; i < r; i++)
        {
            if (s[i] < '0' || s[i] > '9')
                continue;
            num = num * 10 + (s[i] - '0');
        }
        return num;
    }
    else
    {
        int a = calc(s, l, pos);     //递归运算 左边的表达式
        int b = calc(s, pos + 1, r); //右边
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
        //输入表达式
        cout << calc(str, 0, str.size()) << endl;
    }

    system("pause");
    return 0;
}