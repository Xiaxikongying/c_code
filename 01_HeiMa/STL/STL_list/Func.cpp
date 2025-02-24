#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

// list 链表
//优点 可以快速的插入和删除元素
//缺点 占用空间大 遍历速度慢
// STL 提供的是双向循环链表

void printList(list<int> &l)
{
    for (list<int>::iterator it = l.begin(); it != l.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

bool myCompare(int v1, int v2)
{
    return v1 > v2;
    //降序 使 第一个数 > 第二个数 时返回true
}

// 1.构造函数 与vector 相同
void test01()
{
    list<int> l1;
    l1.push_back(10);
    l1.push_back(20);
    l1.push_back(30);
    l1.push_back(40);

    printList(l1);

    list<int> l2(l1.begin(), l2.end());
    list<int> l3(l1);
    list<int> l4(10, 999);
}

//------------------------------------------------------------

// 2.赋值与交换 与vector 相同
// l1.swap(l2);

//------------------------------------------------------------

// 3.大小操作 与vector 相同
// size() empty() resize()

//------------------------------------------------------------

// 4.插入与删除 与vector 相同
//push_back() pop_back() push_front() pop_front() insert() erase() clear()
//但是有一个新的删除函数
//remove(elem)  删除list中与elem相同的元素

//------------------------------------------------------------

// 5.大小操作 只有 front() back()
//不可以用 l.at(i) 和 l[] 来访问

//------------------------------------------------------------

// 6.反转和排序
//sort()  reverse()
void test02()
{
    list<int> l1;

    l1.push_back(10);
    l1.push_back(100);
    l1.push_back(30);
    l1.push_back(80);
    l1.push_back(50);

    cout << "反转前：" << endl;
    printList(l1);

    cout << "反转后：" << endl;
    l1.reverse();
    printList(l1);

    // list 的 sort 是成员函数 不是全局函数 （因为list是随机存储）
    cout << "从小到大 排序后：";
    l1.sort();  //从小到大
    printList(l1);

    cout << "从大到小 排序后：";
    l1.sort(myCompare); //从大到小
    printList(l1);
}

//------------------------------------------------------------

// 7.

int main()
{
    test02();
    system("pause");
    return 0;
}