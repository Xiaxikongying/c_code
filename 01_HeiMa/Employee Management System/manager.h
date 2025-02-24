#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

class manager : public worker
{
public:
    manager(int id, string name, int did)
    {
        this->id = id;
        this->name = name;
        this->did = did;
    }

    void showInfo()
    {
        cout << "职工编号:" << this->id
             << "\t职工姓名:" << this->name
             << "\t岗位:" << this->getDname()
             << "\t岗位职责：完成老板的任务，并下发任务给员工" << endl;
        
    }

    string getDname()
    {
        return string("经理");
    }
};