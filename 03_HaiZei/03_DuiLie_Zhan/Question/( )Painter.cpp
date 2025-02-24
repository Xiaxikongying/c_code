#include <iostream>
#include <stack>
using namespace std;

// hai zei oj 265
/*
例如 [(){}]() 是美观的括号序列，而 )({)[}]( 则不是。

现在 Candela想在她绘制的括号序列中，找出其中连续的一段，
满足这段子序列是美观的，并且长度尽量大。你能帮帮她吗？

[[[[]]{}]]
10

((){}[](}
6
*/
#define Max_N 10005
char str[Max_N];
int match[Max_N] = {0};
// match == 0 括号没有合法的匹配
stack<int> s;

int main()
{
    cin >> (str + 1); //从下标 1 开始输入str
    for (int i = 1; str[i]; i++)
    {
        switch (str[i])
        {
        case '(':
        case '[':
        case '{':
            s.push(i);
            //将 i 存入栈中
            break;

        case ')':
        {
            if (!s.empty() && str[s.top()] == '(') // str[s.top()] 表示 栈中上一次压入的左括号
            {
                match[s.top()] = i;
                match[i] = s.top();
                s.pop();
            }
            else
            {
                s.push(i);
            }
        }
        break;

        case ']':
        {
            if (!s.empty() && str[s.top()] == '[')
            {
                match[s.top()] = i;
                match[i] = s.top();
                s.pop();
            }
            else
            {
                s.push(i);
            }
        }
        break;

        case '}':
        {
            if (!s.empty() && str[s.top()] == '{')
            {
                match[s.top()] = i;
                match[i] = s.top();
                s.pop();
            }
            else
            {
                s.push(i);
            }
        }
        break;
        }
    }

    for (int i = 1; str[i]; i++)
    {
        printf("match[%d] = %d\n", i, match[i]);
    }

    int temp = 0, ans = 0;
    int i = 1;
    while (str[i])
    {
        if (match[i])
        {
            temp += match[i] - i + 1;
            //若 match[i] != 0 则match[i]表示与i位置相匹配的下标
            // match[i] - i + 1 即为两个相匹配括号的距离
            i = match[i] + 1;
            // i跳到 两个相匹配括号的下一位
        }
        else
        {
            //表示i处无完美括号
            i++;
            temp = 0;
        }
        if (temp > ans)
            ans = temp;
    }
    cout << ans << endl;

    system("pause");
    return 0;
}

class Solution
{
public:
    bool isValid(String s)
    {
        int len = s.length() / 2;
        for (int i = 0; i < len; i++)
        {
            s = s.replace("()", "").replace("{}", "").replace("[]", "");
        }
        return s.length() == 0;
    }
}