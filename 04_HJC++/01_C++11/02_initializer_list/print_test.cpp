#include <iostream>
using namespace std;

void print(initializer_list<int> val)
{
    for (auto p : val)
        cout << p << "  ";
    cout << endl;
}

int main()
{
    print({1, 2, 3, 4, 5});
    system("pause");
    return 0;
}
