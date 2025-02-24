#include <stack>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
// Hai zei oj 595

int main()
{
    int n;
    cin >> n;
    int flag = 0;
    vector<string> ops(n); //指定ops长度为n
    vector<string> s;      //不指定 s 的长度
    for (int i = 0; i < n; i++)
        cin >> ops[i];

    string target;
    cin >> target;

    for (int i = 0; i < n; i++)
    {
        if (ops[i] == target)
        {
            s.push_back(ops[i]);
            flag = 1;
            break;
        }
        else if (ops[i] == "return")
        {
            s.pop_back();
        }
        else
        {
            s.push_back(ops[i]);
        }
    }
    if (flag == 1)
    {
        for (int i = 0; i < s.size();i++)
        {
            if(i)
                cout << "->";
            cout << s[i];
        }
        cout << endl;
    }
    else
    {
        cout << "NOT REFERENCED" << endl;
    }

    system("pause");
    return 0;
}