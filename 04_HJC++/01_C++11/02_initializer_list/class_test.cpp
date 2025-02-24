#include <iostream>
#include <algorithm>
using namespace std;

class Test
{
public:
    Test(int a, int b)
    {
        cout << "(int,int): " << a << " " << b << endl;
    }
/*
    Test(initializer_list<int> vals)
    {
        cout << "initializer_list: ";
        for (auto a : vals)
            cout << a << " ";
        cout << endl;
    }
*/
     Test(int a, int b, int c)
    {
        cout << "(int,int,int): " << a << " " << b << " " << c << endl;
    }
};
int main()
{
    Test a(1, 2);
    Test b{1, 2};
    Test c{1, 2, 3};
    Test d = {1, 2};
    Test e = {1, 2, 3};
    Test f({1, 2, 3});
    /*
        int m = min({1, 2, 3, 4, 5, 0, 6});
        cout << "min: "<<m << endl;

        pair<int, int> p = minmax({1, 2, 3, 4, 0, 5});
        cout << p.first << " " <<p.second << endl;
        */
    system("pause");
    return 0;
}
