#include <iostream>
#include <map>
#include <vector>
#include <ctime>
using namespace std;
#define CEHUA 0
#define MEISHU 1
#define YANFA 2

class worker
{
public:
    string name;
    int salary;
};

void creatWorker(vector<worker> &v)
{
    string nameSeed = "ABCDEFGHIJ";
    for (int i = 0; i < 10; i++)
    {
        worker w;
        w.name = "员工";
        w.name += nameSeed[i];
        w.salary = rand() % 10000 + 10000; // 10000-19999
        v.push_back(w);
    }
}

void setGroup(vector<worker> &vw, multimap<int, worker> &mw)
{
    for (vector<worker>::iterator it = vw.begin(); it != vw.end(); it++)
    {
        int did = rand() % 3; // 0 1 2
        mw.insert(pair<int, worker>(did, *it));
    }
}

void showworker1(multimap<int, worker> &mw)
{
    for (multimap<int, worker>::iterator it = mw.begin(); it != mw.end(); it++)
    {
        if (it->first == 0)
        {
            cout << "部门：策划部   姓名：" << it->second.name << "   薪水：" << it->second.salary << endl;
        }
        if (it->first == 1)
        {
            cout << "部门：美术部   姓名：" << it->second.name << "   薪水：" << it->second.salary << endl;
        }
        if (it->first == 2)
        {
            cout << "部门：研发部   姓名：" << it->second.name << "   薪水：" << it->second.salary << endl;
        }
    }
}

void showworker2(multimap<int, worker> &mw)
{
    multimap<int, worker>::iterator pos = mw.find(CEHUA);
    int count = mw.count(CEHUA);
    int index = 0;
    cout << "策划部门：" << endl;
    for (; pos != mw.end() && index < count; pos++, index++)
    {
        cout << "姓名：" << pos->second.name << "   薪水：" << pos->second.salary << endl;
    }
    cout << endl;
    cout << "-----------------------------------------" << endl;
    cout << endl;
    pos = mw.find(MEISHU);
    count = mw.count(MEISHU);
    index = 0;
    cout << "美术部门：" << endl;
    for (; pos != mw.end() && index < count; pos++, index++)
    {
        cout << "姓名：" << pos->second.name << "   薪水：" << pos->second.salary << endl;
    }

    cout << endl;
    cout << "-----------------------------------------" << endl;
    cout << endl;
    pos = mw.find(YANFA);
    count = mw.count(YANFA);
    index = 0;
    cout << "研发部门：" << endl;
    for (; pos != mw.end() && index < count; pos++, index++)
    {
        cout << "姓名：" << pos->second.name << "   薪水：" << pos->second.salary << endl;
    }
}

int main()
{
    srand((unsigned int)time(NULL));
    vector<worker> vw;
    //创建员工
    creatWorker(vw);
    /*
    for (vector<worker>::iterator it = vw.begin(); it != vw.end();it++)
    {
        cout << "姓名: " << it->name << "  工资: " << it->salary << endl;
    }
    */

    //员工分组
    multimap<int, worker> mw;
    setGroup(vw, mw);
    //showworker1(mw);
    showworker2(mw);

    system("pause");
}