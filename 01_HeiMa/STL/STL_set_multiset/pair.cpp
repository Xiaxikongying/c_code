#include <iostream>
using namespace std;

int main()
{
    pair<string, int> p1("Tom", 18);
    cout << "string: " << p1.first << "   int: " << p1.second << endl;

    pair<int, char> p2 = make_pair(10, 'a');
    cout << "int: " << p2.first << "   char: " << p2.second << endl;

    system("pause");
    return 0;
}