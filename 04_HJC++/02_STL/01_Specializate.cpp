#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 模板的泛化与特化
template <typename T>
class A
{
public:
    A()
    {
        cout << "type" << endl;
    }
};

template <>
class A<int>
{
public:
    A()
    {
        cout << "int" << endl;
    }
};

template <>
class A<string>
{
public:
    A() { cout << "string" << endl; }
};

template <typename T>
class A<T *>
{
public:
    A() { cout << "type *" << endl; }
};

int main()
{
    vector<int> v{1, 9, 3, 7, 8, 4, 5};
    int arr[]{1, 5, 3, 7, 2, 8};

    sort(v.begin(), v.end());
    sort(arr, arr + 6);

    for (int i : v)
        cout << i << " ";
    cout << endl;

    for (int i : arr)
        cout << i << " ";
    cout << endl;

    system("pause");
    return 0;
}
