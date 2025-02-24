#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

class boss : public worker
{
public:
    boss(int id, string name, int did)
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
             << "\t岗位职责：管理公司所有事物" << endl;
    }

    string getDname()
    {
        return string("老板");
    }
};