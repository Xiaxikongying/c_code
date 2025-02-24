#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

class employee : public worker
{
public:
    employee(int id, string name, int did)
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
             << "\t岗位职责：完成经理交给的任务" << endl;
    }

    string getDname()
    {
        return string("员工");
    }
};