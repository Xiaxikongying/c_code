#include <iostream>
#include <set>
using namespace std;

// set容器 自定义的排序规则是 从小到大
//如何改成从大到小？
//而且对于自定义类型的数据 无法排序

class myCompare1
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

class person
{
public:
    string name;
    int age;
    person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
};

class myCompare2
{
public:
    bool operator()(person p1, person p2)
    {
        return p1.age < p2.age;
        //升序
    }
};

void printSet(set<int> &s)
{
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    set<int> s1;
    s1.insert(10);
    s1.insert(80);
    s1.insert(100);
    s1.insert(50);
    s1.insert(40);
    cout << "默认排序：" << endl;
    printSet(s1);


    set<int, myCompare1> s2;
    s2.insert(10);
    s2.insert(80);
    s2.insert(100);
    s2.insert(50);
    s2.insert(40);
    cout << "降序排列：" << endl;

    for (set<int, myCompare1>::iterator it = s2.begin(); it != s2.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test02()
{
    person p1("刘备", 35);
    person p2("曹操", 45);
    person p3("孙权", 40);
    person p4("赵云", 25);

    set<person, myCompare2> s;
    s.insert(p1);
    s.insert(p2);
    s.insert(p3);
    s.insert(p4);

    for (set<person, myCompare2>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << (*it).name << " " << (*it).age << endl;
    }
}

int main()
{
    test02();
    system("pause");
    return 0;
}