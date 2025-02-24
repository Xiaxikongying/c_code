#include <iostream>
#include <set>
using namespace std;

// set 和 multiset 是关联容器 只需包含一个头文件 <set> 底层是用二叉树实现
// set 不允许存储相同的元素
//而multiset可以

void printSet(set<int> &s)
{
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// set容器的特点
//不允许插入相同的元素  所有插入的元素都会自动排序

// 1.构造
void test01()
{
    set<int> s1;
    //插入数据只有insert方法
    s1.insert(10);
    s1.insert(80);
    s1.insert(100);
    s1.insert(50);
    s1.insert(40);
    // s1.insert(40);  不会报错 但也不会插入
    printSet(s1);
}

// 2.大小
// empty()  size()  swap()   没有 resize

// 3.插入和删除
// insert()  erase(s.begin())  erase(elem) 直接删除elem

// 4.查找和统计
//  find()  count()
void test02()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(80);
    s1.insert(100);
    s1.insert(50);
    s1.insert(40);

    set<int>::iterator it = s1.find(30); // find 返回的是对应元素的迭代器
    if (it == s1.end())
    {
        cout << "未找到该元素" << endl;
    }
    else
    {
        cout << "找到该元素" << endl;
    }

    cout << s1.count(100) << endl; // count 返回的是对应元素的个数(int)  在set中只有0或1
}

// 5. set 和 multiset 的区别
void test03()
{
    set<int> s;
    pair<set<int>::iterator, bool> ret = s.insert(10);

    if (ret.second)
    {
        cout << "第一次插入成功" << endl;
    }
    else
    {
        cout << "第一次插入失败" << endl;
    }

    ret = s.insert(10);
    if (ret.second)
    {
        cout << "第二次插入成功" << endl;
    }
    else
    {
        cout << "第二次插入失败" << endl;
    }

    multiset<int> ms;
    ms.insert(10);
    ms.insert(10);
    for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    test03();
    system("pause");
    return 0;
}