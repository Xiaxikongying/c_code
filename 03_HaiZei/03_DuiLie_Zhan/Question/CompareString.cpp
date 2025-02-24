#include <iostream>
#include <stack>
using namespace std;
//-----leetcode 844
/*
给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器后，
如果两者相等，返回 true 。#代表退格字符。

注意：如果对空文本输入退格字符，文本继续为空。

输入：s = "ab#c", t = "ad#c"
输出：true
解释：s 和 t 都会变成 "ac"。

*/

class Solution
{
public:
    void pushStack(string &s, stack<char> &stk)
    {
        for (int i = 0; s[i]; i++)
        {
            if (s[i] == '#')
            {
                if (!stk.empty())
                    stk.pop();
            }
            else
                stk.push(s[i]);
        }
        return;
    }

    bool backspaceCompare(string s, string t)
    {
        stack<char> s1, s2;
        pushStack(s, s1);
        pushStack(t, s2);

        if (s1.size() != s2.size())
            return false;

        while (!s1.empty())
        {
            if (s1.top() != s2.top())
            {
                return false;
            }
            else
            {
                s1.pop();
                s2.pop();
            }
        }
        return true;
    }
};
