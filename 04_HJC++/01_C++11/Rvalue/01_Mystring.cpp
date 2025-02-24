#include <iostream>
#include <cstring>
#include <vector>
#include <time.h>
using namespace std;

class Mystring
{
public:
    int len;
    char *data;
    void init_data(const char *D)
    {
        data = new char[len + 1];
        memcpy(data, D, len);
        data[len] = '\0';
    }

    Mystring() : len(0), data(nullptr) {}
    Mystring(const char *p) : len(strlen(p)) { init_data(p); }

    Mystring(const Mystring &s) : len(s.len) { init_data(s.data); }
    Mystring(Mystring &&s) : len(s.len), data(s.data)
    {
        s.data = nullptr;
        s.len = 0;
    }

    Mystring operator=(const Mystring &s)
    {
        if (&s != this)
        {
            if (data)
                delete data;
            len = s.len;
            init_data(s.data);
        }
        return *this;
    }

    Mystring operator=(Mystring &&s)
    {
        if (&s != this)
        {
            if (data)
                delete data;
            len = s.len;
            data = s.data;
            s.data = nullptr;
            s.len = 0;
        }
        return *this;
    }
};

int main()
{
    vector<Mystring> c;
    char buf[] = "this is a test";

    clock_t t1, t2, t3, t4;
    t1 = clock();

    for (int i = 0; i < 30000000; i++)
        c.push_back(Mystring(buf));
    t2 = clock();
    cout << "Mystring move ctor " << t2 - t1 << endl;

    vector<Mystring> c2(c);
    t3 = clock();
    cout << "vector copy ctor " << t3 - t2 << endl;

    vector<Mystring> c3(move(c));
    t4 = clock();
    cout << "vector move ctor " << t4 - t3 << endl;

    system("pause");
    return 0;
}
