#include <iostream>
#include <vector>
using namespace std;

// 定义一个模板模板参数
template <typename T, template <class...> class Container>
class MyContainer
{
public:
    Container<T> container;

    void addElement(T elem)
    {
        container.push_back(elem);
    }
};

int main()
{
    MyContainer<int, vector> Vec;
    Vec.addElement(42);
    cout << Vec.container.at(0) << endl; // 输出 42
    system("pause");
    return 0;
}
