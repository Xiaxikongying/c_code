#include <iostream>
#include <vector>
using namespace std;
template <typename T>
using vec = vector<T, allocator<T>>;

// 定义一个模板模板参数
template <typename T, template <class> class Container>
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
    vec<int> a;
    MyContainer<string, a> V;
    V.addElement("hello");
    cout << Vec.container.at(0) << endl; // 输出 42
    system("pause");
    return 0;
}