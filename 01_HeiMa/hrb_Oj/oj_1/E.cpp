#include <iostream>
using namespace std;

int main()
{
    char stack[60];
    string s;
    while (cin >> s)
    {
        int top = -1;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                top++;
                stack[top] = s[i];
            }
            if (s[i] == ')' && stack[top] != '(')
            {
                cout << "no" << endl;
                break;
            }
            if (s[i] == ']' && stack[top] != '[')
            {
                cout << "no" << endl;
                break;
            }
            if (s[i] == '}' && stack[top] != '{')
            {
                cout << "no" << endl;
                break;
            }

            if (s[i] == ')' && stack[top] == '(')
                top--;
            if (s[i] == ']' && stack[top] == '[')
                top--;
            if (s[i] == '}' && stack[top] == '{')
                top--;
        }
        if (top == -1)
            cout << "yes" << endl;
    }
    system("pause");
}