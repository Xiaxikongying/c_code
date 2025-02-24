#include <iostream>
using namespace std;

template <typename T>
T Mymax(const T &val)
{
    return val;
}
template <typename T, typename... Types>
T Mymax(const T &val, const Types &...args)
{
    return max(val, Mymax(args...));
}

int main()
{
    cout << Mymax(1, 2, 3, 4, 999, 20, 4654, 22) << endl;
    system("pause");
    return 0;
}
