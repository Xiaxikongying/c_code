#pragma once
#include <iostream>
using namespace std;

class worker
{
public:
    virtual void showInfo() = 0;
    virtual string getDname() = 0;
    int id;
    string name;
    int did;
};