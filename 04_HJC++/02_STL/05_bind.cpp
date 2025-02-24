#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
using namespace std::placeholders;

struct Add
{
    int a;
    int test(int b)
    {
        return a + b;
    }
    int operator()(int a, int b)
    {
        return a + b;
    }
};

struct ADD
{
    int a;
    int test(int b) { return a + b; }
};

double my_divide(double a, double b) // 除法
{
    return a / b;
}

int main()
{
    auto d1 = bind(my_divide, _1, _2);
    cout << "d1 == " << d1(10, 3) << endl;

    auto d2 = bind(my_divide, _2, _1);
    cout << "d2 == " << d2(10, 3) << endl;

    auto d3 = bind(my_divide, _1, 5);
    cout << "d3 == " << d3(10) << endl;

    auto d4 = bind<int>(my_divide, 10, 3);
    cout << "d4 == " << d4() << endl;

    Add add;
    auto bound_add = bind(add, 10, 20);
    int result = bound_add(); // 等价于 add(10, 20)
    cout << result << endl;

    Add add2{20};
    auto bound_add2 = bind(&Add::test, add2, _1);
    cout << bound_add2(20) << endl;

    ADD a1{5};
    auto ba1 = bind(ADD::test, a1, 10);
    cout << "ba1 = " << ba1() << endl;

    auto ba2 = bind(&ADD::a, a1);
    cout << "ba2 = " << ba2() << endl;

    int seed = 0;

    system("pause");
    return 0;
}
class CustomerHash
{
public:
    size_t operator()(constCustomer &c)
    {
        return hash_val(c.fname, c.lname, c.age);}
}
