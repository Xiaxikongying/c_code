#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print()
{
    cout << "最后一次调用咯" << endl;
}

template <typename T, typename... Types>
void print(const T &firstArg, const Types &...args)
{
    cout << firstArg << endl;
    print(args...);
}

int main()
{

    print(1, 2);
    system("pause");
    return 0;
}
