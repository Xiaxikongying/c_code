#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void printDeque(deque<int> &d)
{
    for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 1.赋值  deque 与 vector 赋值操作完全相同

// 2.大小  empty() size() resize() 与vector相同
//但deque没有 capacity()函数

void test01()
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque(d1);
}

// 3.插入与删除
//与vector相同  push_back() pop_back() insert() clear() rease()
//但deque相比vector多2个  push_front() pop_front()

// 4.数据存取
// d1.at(2)  d1[2]  d1.front()  d1.end()

// 5.排序
//vector 也可以用sort
void test02()
{
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(40);
    d.push_front(50);
    d.push_front(100);

    cout << "排序前：" << endl;
    printDeque(d);

    sort(d.begin(), d.end());
    cout << "排序后：" << endl;
    printDeque(d);
}

int main()
{
    test02();
    system("pause");
    return 0;
}