#include <iostream>
using namespace std;

void fan(string s)
{
    int len = s.length();
    for (int i = 0; i < len/2; i++)
    {
        char t = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = t;
    }
    cout << s << endl;
}

int main()
{
    string s;
    while (cin >> s)
    {
        fan(s);
       
    }
    system("pause");
    return 0;
}

/*
A.反序字符串

写一个函数，实现字符串的反序输出。在主函数中输入和使用函数，实现这个功能。

Input
有多组数据。每行一个字符串，由大写字母、小写字母和数字组成。字符串长度小于100.

Output
对于每组输入数据，输出逆序后的字符串。每组输出占一行。

Sample Input
123456abcdef

Sample Output
fedcba654321

*/