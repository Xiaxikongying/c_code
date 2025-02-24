#include <iostream>
#include <deque>
using namespace std;

//deque与vector的区别
//deque是双端开口的容器 可以对开头进行插入和删除 
//push_front() 和 pop_front()


//构造函数与vector相同
void test01()
{
    deque<int> d1;
    for (int i = 0; i < 10;i++)
    {
        d1.push_back(i);
    }
    for (deque<int>::iterator::it = d1.begin(); it != d1.end();it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    deque<int> d2(d1.begin(), d1.end());

    // 3.
    deque<int> d3(10, 100); // 10个100

    // 4.
    deque<int> d4(d1);
}

int main()
{

}
