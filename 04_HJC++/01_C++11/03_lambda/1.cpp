#include <iostream>
using namespace std;

int main()
{
    int id = 0;
    auto f = [&]() mutable
    {
        cout << "id== " << id << endl;
        ++id;
    };
    f();
    f();
    id = 42;
    f();
    f();
    cout << "id== " << id << endl;
    cout << typeid(f).name() << endl;

    system("pause");
    return 0;
}
