//---------------------leetcod 20---------
/*
20. 有效的括号
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。
 
*/
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> sk;

        if (s[0] == ')' || s[0] == ']' || s[0] == '}' || s.length() % 2 == 1)
            return false;
            
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                sk.push(s[i]);
            }
            else
            {
                if (!sk.empty())
                {
                    if (s[i] == ')' && sk.top() == '(')
                    {
                        sk.pop();
                    }
                    else if (s[i] == ']' && sk.top() == '[')
                    {
                        sk.pop();
                    }
                    else if (s[i] == '}' && sk.top() == '{')
                    {
                        sk.pop();
                    }
                    else
                        return false;
                }
                else
                    return false;
            }
        }
        return sk.empty();
    }
};