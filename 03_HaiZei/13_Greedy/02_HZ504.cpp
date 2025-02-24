#include <iostream>
using namespace std;

/*
去掉某几个数
309054  2
54
*/
int main()
{
    string s;
    cin >> s;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int j = 0;
        while (s[j + 1] != '\0' && s[j + 1] >= s[j])
            j++;
        s.erase(j, 1);
    }

    int flag = 1;
    for (int i = 0; s[i]; i++)
    {
        if (s[i] == '0' && flag)
            continue;
        cout << s[i];
        flag = 0;
    }
    cout << endl;

    system("pause");
    return 0;
}