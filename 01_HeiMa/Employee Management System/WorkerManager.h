#pragma once
#include <iostream>
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include <fstream>

#define FILENAME "empFile.txt"
using namespace std;

class WorkerManager
{
public:
    WorkerManager();

    int EmpNum;
    worker **EmpArray;
    bool isFileEmpty;

    
    void show_Menu();
    void exitSystem();
    void save();//将当前数组中的数据存入文件中
    int getEmpNum();
    void initEmp();  //初始化员工
    int isExist(int id);

    void add_Emp();
    void show_Emp();
    void delete_Emp();
    void mod_Emp();
    void find_Emp();
    void srot_Emp();
    void clean_Emp();

    ~WorkerManager();
};