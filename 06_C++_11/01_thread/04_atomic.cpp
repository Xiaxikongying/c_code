#include <iostream>
#include <thread>
#include <mingw.thread.h>
#include <atomic>
using namespace std;
void thread_job()
{
    cout << "1111" << endl;
}

int main()
{
    thread th[3];
    for (int i = 0; i < 3; i++)
    {
        th[i] = thread(&thread_job); // 使用临时变量赋值
        th[i].detach();
    }
    bool flag;
    while (cin >> flag)
    {
        if (flag)
            cd.notify_one();
    }
    system("pause");
    return 0;
}
