#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <mingw.thread.h>
#include <mingw.mutex.h>
#include <mingw.condition_variable.h>
using namespace std;

condition_variable cd;
mutex mut;
void thread_job()
{
    unique_lock<mutex> lock(mut);
    cout << "1111" << endl;
    cd.wait(lock);
    cout << "2222" << endl;
}

int main()
{
    thread th[3];
    for (int i = 0; i < 3; i++)
    {
        th[i]= thread(&thread_job); //使用临时变量赋值
        th[i].detach();
    }
    bool flag;
    while(cin>>flag)
    {
        if(flag)
            cd.notify_one();
    }
    system("pause");
    return 0;
}
