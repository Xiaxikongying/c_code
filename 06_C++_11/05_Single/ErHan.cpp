#include <iostream>
using namespace std;

class Single
{
private:
    Single() {}
    ~Single(){}
    Single(const Single &) = delete;
    Single &operator=(const Single &) = delete;
    static Single m_Single;
public:
    static Single *getSingle()
    {
        return &m_Single;
    }
};
Single Single::m_Single;
int main()
{
    Single *s = Single::getSingle();
    cout << s << endl;
    Single *s1 = Single::getSingle();
    cout << s1 << endl;
    system("pause");
    return 0;
}
