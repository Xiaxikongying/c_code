#include <iostream>
using namespace std;
void print()
{
    cout << "最后一次调用咯" << endl;
}

template <typename T, typename... Types>
void print(const T &firstArg, const Types &...args)
{
    cout << firstArg << "\t";
    cout << "this is frist test" << endl;
    print(args...);
}

template <typename T1, typename T2, typename... Types>
void print(const T1 &firstArg, const T2 &secondArg, const Types &...args)
{
    cout << firstArg << "  " << secondArg << "\t";
    cout << "this is second test" << endl;
    print(args...);
}

int main()
{

    print(1, 2, 3.3, 4, 5);
    system("pause");
    return 0;
}
