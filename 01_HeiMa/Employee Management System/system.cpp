#include <iostream>
#include "WorkerManager.h"
#include "WorkerManager.cpp"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h" 
using namespace std;

int main()
{

        WorkerManager wm;

        int select;

        while (true)
        {
            wm.show_Menu();
            int select;
            cin >> select;

            switch (select)
            {
            case 0:
                wm.exitSystem();
                break;
            case 1:
                wm.add_Emp();
                break;
            case 2:
                wm.show_Emp();
                break;
            case 3:
                wm.delete_Emp();
                break;
            case 4:
                wm.mod_Emp();
                break;
            case 5:
                wm.find_Emp();
                break;
            case 6:
                wm.srot_Emp();
                break;
            case 7:
                wm.clean_Emp();
                break;
            default:
                system("cls");
                break;
            }
        }
    
    system("pause");
    return 0;
}

/*
    //测试3种职工

    worker *worker = NULL;
    worker = new employee(1, "张三",3);
    worker->showInfo();
    delete worker;

    worker = new manager(2, "李四", 2);
    worker->showInfo();
    delete worker;

    worker = new boss(3, "王五", 1);
    worker->showInfo();
    delete worker;
*/