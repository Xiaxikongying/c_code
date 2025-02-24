#include <iostream>
using namespace std;

void Myprintf(const char *s)
{
    while (*s)
    {
        if ((*s) == '%' && *(++s) != '%')
        {
            cout << "ERROR!!!" << endl;
            //throw runtime_error("error");
            // return;
        }
        cout << *s;
        s++;
    }
}

template <typename T, typename... Types>
void Myprintf(const char *s, T val, Types... args)
{
    while (*s)
    {
        if ((*s) == '%' && *(++s) != '%')
        {
            cout << val;
            Myprintf(++s, args...);
            return;
        }
        cout << *s;
        s++;
    }
    cout << "ERROR!!!" << endl;
}

int main()
{
    Myprintf("this is a test %d aaaa %s dadlhuhlhl%dsda\n", 152, "string"); // 由于\n是算是一个字符，所以会直接cout输出
    system("pause");
    return 0;
}
