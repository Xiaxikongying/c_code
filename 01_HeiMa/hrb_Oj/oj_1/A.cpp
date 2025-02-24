#include <iostream>
#include <string>
using namespace std;

int main()
{
    string cl[20];
    for (int i = 0; i < 10; i++)
    {
        getline(cin, cl[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        cout << cl[i] << endl;
    }
    system("pause");
    return 0;
}