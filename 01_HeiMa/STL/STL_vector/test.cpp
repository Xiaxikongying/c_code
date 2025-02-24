#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void myPrint(int v)
{
    cout << v << endl;
}

class person
{
public:
    int age;
    string name;
    person(int age, string name)
    {
        this->age = age;
        this->name = name;
    }
};

void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(100);
    v.push_back(40);
    v.push_back(50);

    // iterator 是迭代器
    vector<int>::iterator itBegin = v.begin(); //起始迭代器   指向容器第一个元素
    vector<int>::iterator itEnd = v.end();     //结束迭代器 指向最后一个元素的下一个位置

    //第一种遍历方法
    while (itBegin != itEnd)
    {
        cout << *itBegin << endl;
        //*itBegin  解引用出来的数据是一个int数据 (即 是vector后<>中的内容)
        itBegin++;
    }

    sort(v.begin(), v.end());

    //第二种遍历方法
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << endl;
        //*it  解引用出来的数据是一个int数据
    }

    //第三种遍历方法  利用STL提供的遍历算法  需要头文件 <algorithm>
    //for_each(v.begin(), v.end(), myPrint);

    // myPrint(*v.begin());
}

void test02()
{
    vector<person> v;
    person p1(10, "aaa");
    person p2(20, "bbb");
    person p3(30, "ccc");
    person p4(40, "ddd");
    person p5(50, "eee");

    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    for (vector<person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "姓名：" << (*it).name << "  年龄：" << (*it).age << endl;
        // cout << "姓名：" << it->name << "  年龄：" <<it->age << endl;
    }
}

void test03() // vector 嵌套容器
{
    vector<vector<int>> v;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    for (int i = 0; i < 4; i++)
    {
        v1.push_back(i);
        v2.push_back(i + 1);
        v3.push_back(i + 2);
        v4.push_back(i + 3);
    }

    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
    {
        for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
        {
            cout << (*vit) << "  ";
        }
        cout << endl;
    }
}

int main()
{
     test01();
    // test02();
    //test03();
    system("pause");
    return 0;
}