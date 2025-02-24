#include <iostream>
#include <queue>
using namespace std;

// queue  先进先出  （类似于排队） 不可以遍历
//队头只能移除数据 队尾只能进入数据
// pop() push() back() front() empty() size()

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

void test01()
{
    queue<person> q;

    person p1("唐僧", 20);
    person p2("孙悟空", 2000);
    person p3("猪八戒", 1000);
    person p4("沙僧", 800);

    q.push(p1);
    q.push(p2);
    q.push(p3);
    q.push(p4);

    while (!q.empty())
    {
        cout << q.front().name << " " << q.front().age << endl;
        cout << q.back().name << " " << q.back().age << endl;
        q.pop();
    }
}

int main()
{
    test01();
    system("pause");
    return 0;
}