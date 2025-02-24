#include <iostream>
#include <mutex>
#include <mingw.mutex.h>
using namespace std;

class Single
{
private:
    Single() {}
    ~Single(){};
    Single(const Single &) = delete;
    Single &operator=(const Single &) = delete;
    static Single *m_Single;
    static mutex mtx;

public:
    static Single *getSingle()
    {
        if (m_Single == nullptr)
        {
            unique_lock<mutex> lock(mtx);
            if (m_Single == nullptr)
            {
                m_Single = new Single;
            }
            lock.unlock();
        }
        return m_Single;
    }
    void destroy()
    {
        if (m_Single)
            delete m_Single;
    }
};
Single *Single::m_Single = nullptr;
mutex Single::mtx;

int main()
{
    Single *s = Single::getSingle();
    cout << s << endl;
    Single *s1 = Single::getSingle();
    cout << s1 << endl;
    system("pause");
    return 0;
}
