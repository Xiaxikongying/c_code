#include <iostream>
#include <thread>
#include <mutex>
#include <mingw.thread.h>
#include <mingw.mutex.h>

using namespace std;
/*
RAIIC++很重要的思想
resourceaccess is init...资源获取即初始化 RAII
lock_guard  unique_lock管理互斥锁，让互斥锁使用更方便更安全(可以避免死锁）
lock_guard  unique_lock遵循RAII
lock_guard lck生命周期结束 会自动释放锁.
如果需要在中途释放锁咋办？可以使用uqniue_lock也可以借助花括号实现
unique_lock 可以中途释放锁      Lock_guard 耗费的资源更少 更快.
锁锁定代码长度：粒度锁定的代码长度越长，锁的粒度越大-〉影响影响并发的效率
*/

int a = 0;
mutex mtx;
void AddThread()
{
    for (int i = 0; i < 100; ++i)
    {
        // lock_guard<mutex> unlck(mtx);  声明周期结束才释放锁
        unique_lock<mutex>unlck(mtx);   //unique_lock 可以自行选择时机释放
        ++a;
        unlck.unlock();
        cout << a << endl;
    }
}

int main()
{
    thread th(&AddThread);
    th.join();
    system("pause");
    return 0;
}
