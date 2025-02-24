#include "WorkerManager.h"

WorkerManager::WorkerManager()
{
    //文件不存在时
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    if (!ifs.is_open())
    {
        cout << "文件不存在" << endl;
        this->EmpNum = 0;
        this->EmpArray = NULL;
        this->isFileEmpty = true;
        ifs.close();
        return;
    }

    //文件为空时
    char ch;
    ifs >> ch; //读取文件的一个字符
    if (ifs.eof())
    {
        cout << "文件为空" << endl;
        this->EmpNum = 0;
        this->EmpArray = NULL;
        this->isFileEmpty = true;
        ifs.close();
        return;
    }

    //文件存在并且有数据时
    int num = this->getEmpNum();
    if (num != 0)
    {
        cout << "现有的职工人数为：" << num << endl;
        this->EmpNum = num;
        this->isFileEmpty = false;
        this->EmpArray = new worker *[this->EmpNum];
        this->initEmp();
    }
}

void WorkerManager::show_Menu()
{
    cout << "*********************************************" << endl;
    cout << "**********  欢迎使用职工管理系统!  **********" << endl;
    cout << "************** 0.退出管理程序  **************" << endl;
    cout << "************** 1.增加职工信息  **************" << endl;
    cout << "************** 2.显示职工信息  **************" << endl;
    cout << "************** 3.删除职工信息  **************" << endl;
    cout << "************** 4.修改职工信息  **************" << endl;
    cout << "************** 5.查找职工信息  **************" << endl;
    cout << "************** 6.按照编号排序  **************" << endl;
    cout << "************** 7.清空所有文档  **************" << endl;
    cout << "*********************************************" << endl;
    cout << endl;
    cout << "请输入您所需要的服务" << endl;
}

void WorkerManager::exitSystem()
{
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0); //退出函数
}

int WorkerManager::getEmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int did;
    int num = 0;

    while (ifs >> id && ifs >> name && ifs >> did)
    {
        num++;
    }
    return num;
}

void WorkerManager::initEmp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int did;
    int index = 0;

    while (ifs >> id && ifs >> name && ifs >> did)
    {
        worker *w = NULL;
        switch (did)
        {
        case 1:
            w = new employee(id, name, 1);
            break;
        case 2:
            w = new manager(id, name, 2);
            break;
        case 3:
            w = new boss(id, name, 3);
            break;
        default:
            break;
        }
        this->EmpArray[index] = w;
        index++;
    }
    ifs.close();
}

void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out);

    //将数组中的数据写入文件中
    for (int i = 0; i < this->EmpNum; i++)
    {
        ofs << this->EmpArray[i]->id << " "
            << this->EmpArray[i]->name << " "
            << this->EmpArray[i]->did << endl;
    }
    ofs.close();
}

int WorkerManager::isExist(int id)
{
    int flag = -1;
    for (int i = 0; i < this->EmpNum; i++)
    {
        if (this->EmpArray[i]->id == id)
        {
            flag = i;
            break;
        }
    }
    return flag;
}

//----------------------------------------------------------------------------------------------------
//----------------------------------------------------------------------------------------------------

void WorkerManager::add_Emp()
{
    cout << "请输入添加员工的数量" << endl;
    int addNum = 0;
    cin >> addNum;
    if (addNum > 0)
    {
        //计算新空间的大小
        int newSize = this->EmpNum + addNum;

        //开辟新空间
        worker **newSpace = new worker *[newSize];

        //将原来的数据 拷贝新的空间下
        if (this->EmpArray != NULL)
        {
            for (int i = 0; i < this->EmpNum; i++)
            {
                newSpace[i] = this->EmpArray[i];
            }
        }
        //添加新的数据
        for (int i = 0; i < addNum; i++)
        {
            int id;
            string name;
            int dSelect;
            cout << "请输入第" << i + 1 << "个新职工的编号" << endl;
            cin >> id;
            for (int i = 0; i < this->EmpNum; i++)
            {
                if (id == this->EmpArray[i]->id)
                {
                    cout << "输入的id已经存在，请重新输入" << endl;
                    cin >> id;
                    i = 0;
                }
            }

            cout << "请输入第" << i + 1 << "个新职工的姓名" << endl;
            cin >> name;

            cout << "请选择该职工的岗位" << endl;
            cout << "1.普通职工\n2.经理\n3.老板 " << endl;
            cin >> dSelect;

            worker *w = NULL;
            switch (dSelect)
            {
            case 1:
                w = new employee(id, name, 1);
                break;
            case 2:
                w = new manager(id, name, 2);
                break;
            case 3:
                w = new boss(id, name, 3);
                break;

            default:
                break;
            }

            //将职工指针保存到数组中
            newSpace[this->EmpNum + i] = w;
        }
        delete[] this->EmpArray;   //释放原来的数组空间
        this->EmpArray = newSpace; //将数组指向新的空间
        this->EmpNum = newSize;    //更改人数
        this->isFileEmpty = false;
        cout << "成功添加" << addNum << "个新职工" << endl;
        this->save();
    }

    else
    {
        cout << "输入数据有误" << endl;
    }

    system("pause");
    system("cls");
}

void WorkerManager::show_Emp()
{
    if (this->isFileEmpty)
    {
        cout << "文件为空或不存在" << endl;
    }
    else
    {
        for (int i = 0; i < this->EmpNum; i++)
        {
            this->EmpArray[i]->showInfo();
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::delete_Emp()
{
    if (this->isFileEmpty)
    {
        cout << "文件为空或不存在" << endl;
    }
    else
    {
        cout << "请输入你要删除的职工的编号" << endl;
        int id = 0;
        cin >> id;
        int index = this->isExist(id);
        if (index != -1)
        {
            for (int i = index; i < this->EmpNum - 1; i++)
            {
                this->EmpArray[i] = this->EmpArray[i + 1];
                //数据前移，覆盖掉index位置的数据
            }
            this->EmpNum--;
            this->save();
            cout << "删除成功！" << endl;
        }
        else
        {
            cout << "未找到该职工" << endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::mod_Emp()
{
    if (this->isFileEmpty)
    {
        cout << "文件为空或不存在" << endl;
    }
    else
    {
        cout << "请输入你要修改的职工的编号" << endl;
        int id = 0;
        cin >> id;
        int index = this->isExist(id);
        if (index != -1)
        {
            cout << "已找到" << this->EmpArray[index]->id << "号职工，请输入新的编号" << endl;
            delete this->EmpArray[index];
            int id;
            string name;
            int did;

            cin >> id;
            cout << "请输入新职工的姓名" << endl;
            cin >> name;
            cout << "请输入新职工的岗位" << endl;
            cout << "1.普通职工\n2.经理\n3.老板 " << endl;
            cin >> did;

            worker *w = NULL;
            switch (did)
            {
            case 1:
                w = new employee(id, name, 1);
                break;
            case 2:
                w = new manager(id, name, 2);
                break;
            case 3:
                w = new boss(id, name, 3);
                break;
            default:
                break;
            }
            this->EmpArray[index] = w;

            this->save();
            cout << "修改成功！" << endl;
        }
        else
        {
            cout << "修改失败，未找到该职工" << endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::find_Emp()
{
    if (this->isFileEmpty)
    {
        cout << "文件为空或不存在" << endl;
    }
    else
    {
        int s = 0;
        cout << "请输入查找的方式" << endl;
        cout << "1.按编号查找。\n2.按姓名查找。" << endl;
        cin >> s;
        if (s == 1)
        {
            cout << "请输入编号" << endl;
            int id;
            cin >> id;
            int index = this->isExist(id);
            if (index != -1)
            {
                cout << "查找成功" << endl;
                cout << "职工信息如下：" << endl;
                this->EmpArray[index]->showInfo();
            }
            else
            {
                cout << "查找失败" << endl;
            }
        }
        else if (s == 2)
        {
            string name;
            bool flag = false;
            cout << "请输入查找人的姓名" << endl;
            cin >> name;
            for (int i = 0; i < this->EmpNum; i++)
            {
                if (name == this->EmpArray[i]->name)
                {
                    cout << "查找成功" << endl;
                    cout << "职工信息如下：" << endl;
                    this->EmpArray[i]->showInfo();
                    flag = true;
                }
            }
            if (!flag)
            {
                cout << "查找失败" << endl;
            }
        }
        else
        {
            cout << "输入选项有误" << endl;
        }
    }
    system("pause");
    system("cls");
}

void WorkerManager::srot_Emp()
{
    if (this->isFileEmpty)
    {
        cout << "文件为空或不存在" << endl;
        system("pause");
        system("cls");
    }
    else
    {
        int s = 0;
        cout << "请选择排序的方式" << endl;
        cout << "1.从小到大。\n2.从大到小。" << endl;
        cin >> s;
        for (int i = 0; i < this->EmpNum; i++)
        {
            int minORmax = i;
            for (int j = i + 1; j < this->EmpNum; j++)
            {
                if (s == 1)
                {
                    if (this->EmpArray[minORmax]->id > this->EmpArray[j]->id)
                    {
                        minORmax = j;
                    }
                }
                else
                {
                    if (this->EmpArray[minORmax]->id < this->EmpArray[j]->id)
                    {
                        minORmax = j;
                    }
                }
            }
            if (i != minORmax)
            {
                worker *temp = this->EmpArray[i];
                this->EmpArray[i] = this->EmpArray[minORmax];
                this->EmpArray[minORmax] = temp;
            }
        }
        cout << "排序成功" << endl;
        this->save();
        this->show_Emp();
    }
}

void WorkerManager::clean_Emp()
{
    cout << "确认是否要清空文件？" << endl;
    cout << "1.是\n2.否" << endl;
    int s = 0;
    cin >> s;
    if (s == 1)
    {
        ofstream ofs(FILENAME, ios::trunc); //删除文件后重新生成
        ofs.close();
        if (this->EmpArray != NULL)
        {
            for (int i = 0; i < this->EmpNum; i++)
            {
                if (this->EmpArray[i] != NULL)
                {
                    delete this->EmpArray[i];
                }
            }
            delete[] this->EmpArray;
            this->EmpArray = NULL;
            this->EmpNum = 0;
            this->isFileEmpty = true;
        }
        cout << "清空成功" << endl;
    }
    system("pause");
    system("cls");
}

WorkerManager::~WorkerManager()
{
    if (this->EmpArray != NULL)
    {
        for (int i = 0; i < this->EmpNum; i++)
        {
            if (this->EmpArray[i] != NULL)
            {
                delete this->EmpArray[i];
                this->EmpArray[i] = NULL;
            }
        }
        delete[] this->EmpArray;
        this->EmpArray = NULL;
        this->EmpNum = 0;
        this->isFileEmpty = true;
    }
}
