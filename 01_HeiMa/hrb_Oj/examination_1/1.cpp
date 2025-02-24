#include <iostream>
using namespace std;

//字符串合并

int main()
{
    int a;
    cin >> a;
    char s1[100];
    char s2[100];
    while (a--)
    {
        cin >> s1;
        cin >> s2;
        int len1 = 0;
        int len2 = 0;
        for (int i = 0; s1[i] != '\0'; i++)
        {
            len1++;
        }
        
        for (int i = 0; s2[i] != '\0'; i++)
        {
            len2++;
        }

        int len = len1 + len2;
        char s[len];
        for (int i = 0; i < len; i++)
        {
            if (i < len1)
                s[i] = s1[i];
            if (i >= len1)
                s[i] = s2[i - len1];
        }

        cout << s << endl;
    }
    system("pause");
    return 0;
}