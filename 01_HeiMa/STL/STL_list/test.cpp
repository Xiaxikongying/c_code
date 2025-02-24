#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

class person
{
public:
    string name;
    int age;
    int height;
    person(string name, int age, int height)
    {
        this->name = name;
        this->age = age;
        this->height = height;
    }
};

void printList(list<person> &l)
{
    for (list<person>::iterator it = l.begin(); it != l.end(); it++)
    {
        cout << "姓名：" << (*it).name << " 年龄：" << (*it).age << " 身高：" << (*it).height << endl;
    }
}

//指定排序规则
bool comparePerson1(person &p1,person &p2)
{
    if(p1.age!=p2.age){
         return p1.age < p2.age;
    //按年龄从小到大
    }
    else{
        return p1.height < p2.height;
        //年龄相同 矮的排在前面
    }
   
}

void test01()
{
    list<person> L;
    person p1("刘备", 35, 175);
    person p2("曹操", 45, 180);
    person p3("孙权", 40, 170);
    person p4("赵云", 25, 190);
    person p5("张飞", 35, 160);
    person p6("关羽", 35, 200);

    L.push_back(p1);
    L.push_back(p2);
    L.push_back(p3);
    L.push_back(p4);
    L.push_back(p5);
    L.push_back(p6);

    cout << "排序前: " << endl;
    printList(L);

    cout << "--------------------------------------------------------------" << endl;

    cout << "按年龄-再按身高-排序后: " << endl;
    L.sort(comparePerson1);
    printList(L);
}


int main()
{
    test01();
    system("pause");
    return 0;

}