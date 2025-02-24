#include <iostream>
using namespace std;

template <typename... values>
class tuple;
template <>
class tuple<> // 空类
{
};

template <template head, typename... tail>
class tuple<head, tail...> : private tuple<tail>
{
    typedef tuple<tail...> inherited;

public:
    tuple() {}
    tuple(head v, tail... vtail) : m_head(v), inherited(vtail...){}
    
};
int main()
{

    system("pause");
    return 0;
}
