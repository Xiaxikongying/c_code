#include <iostream>
#include <thread>
#include <mingw.thread.h>
using namespace std;
// C++11线程/ /#include<thread>
// std：:thread定义线程对象//thread对象要结合两个函数使用
// join 和 detach
// join函数阻塞当前线程直到线程函数退出
// detach将线程对象与线程函数分离，线程不依赖线程对象管理
// join和detach 两者必须其一不然线程对象的回收会影响线程的回收，导致程序崩溃.
// 执行detach之后的线程如何退出
// 设置标志位

void fun(int a, int b)
{
    int c = 100;
    while (c--)
    {
        cout << "a + b" << a + b << endl;
        Sleep(20);
    }
}

int main()
{
    thread th(&fun, 3, 4);
    //th.join();
    th.detach();
    system("pause");
    return 0;
}
