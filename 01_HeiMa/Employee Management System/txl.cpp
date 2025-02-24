#include <iostream>
#include "string"

#define MAX 1000
using namespace std;

struct Person
{
    string name;
    int sex;
    int age;
    string pnumber;
    string addr;
};

struct Addressbooks
{
    Person personarr[MAX];
    int size;
};

int isExist(Addressbooks *abs, string name)
{
    for (int i = 0; i < abs->size; i++)
    {
        if (abs->personarr[i].name == name)
        {
            return i;
        }
    }
    return -1;
}

void addperson(Addressbooks *abs)
{
    if (abs->size == MAX)
    {
        cout << "人数已满" << endl;
    }
    else
    {
        string name;
        int sex;
        int age;
        string pnumber;
        string addr;

        cout << "请输入姓名" << endl;
        cin >> name;
        abs->personarr[abs->size].name = name;

        cout << "请输入性别：1为男 2为女" << endl;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personarr[abs->size].sex = sex;
                break;
            }
            else
            {
                cout << "输出有误" << endl;
            }
        }

        cout << "请输入年龄" << endl;
        cin >> age;
        abs->personarr[abs->size].age = age;

        cout << "请输入电话" << endl;
        cin >> pnumber;
        abs->personarr[abs->size].pnumber = pnumber;

        cout << "请输入住址" << endl;
        cin >> addr;
        abs->personarr[abs->size].addr = addr;
    }
    abs->size++;
    cout << "你添加成功" << endl;
    system("pause"); //按任意键继续
    system("cls");
}

void showperson(Addressbooks *abs)
{
    if (abs->size == 0)
    {
        cout << "当前记录为空" << endl;
    }
    else
    {
        for (int i = 0; i < abs->size; i++)
        {
            cout << "姓名：" << abs->personarr[i].name << "\t";
            cout << "性别：" << (abs->personarr[i].sex == 1 ? "男" : "女") << "\t";
            cout << "年龄：" << abs->personarr[i].age << "\t";
            cout << "电话：" << abs->personarr[i].pnumber << "\t";
            cout << "住址：" << abs->personarr[i].addr << endl;
        }
    }
    system("pause"); //按任意键继续
    system("cls");
}

void deleteperson(Addressbooks *abs)
{
    cout << "请输入你要删除的人" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        for (int i = ret; i < abs->size; i++)
        {
            abs->personarr[i] = abs->personarr[i + 1];
        }
        abs->size--;
        cout << "删除成功" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
    system("pause"); //按任意键继续
    system("cls");
}

void findperson(Addressbooks *abs)
{
    cout << "请输入你要查找的人" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        cout << "姓名：" << abs->personarr[ret].name << "\t";
        cout << "性别：" << (abs->personarr[ret].sex == 1 ? "男" : "女") << "\t";
        cout << "年龄：" << abs->personarr[ret].age << "\t";
        cout << "电话：" << abs->personarr[ret].pnumber << "\t";
        cout << "住址：" << abs->personarr[ret].addr << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
    system("pause"); //按任意键继续
    system("cls");
}

void modifyperson(Addressbooks *abs)
{
    cout << "请输入你要修改的人" << endl;
    string name;
    cin >> name;
    int ret = isExist(abs, name);
    if (ret != -1)
    {
        string name;
        int sex;
        int age;
        string pnumber;
        string addr;

        cout << "请输入姓名" << endl;
        cin >> name;
        abs->personarr[ret].name = name;

        cout << "请输入性别：1为男 2为女" << endl;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personarr[ret].sex = sex;
                break;
            }
            else
            {
                cout << "输出有误" << endl;
            }
        }

        cout << "请输入年龄" << endl;
        cin >> age;
        abs->personarr[ret].age = age;

        cout << "请输入电话" << endl;
        cin >> pnumber;
        abs->personarr[ret].pnumber = pnumber;

        cout << "请输入住址" << endl;
        cin >> addr;
        abs->personarr[ret].addr = addr;
    }
    else
    {
        cout << "查无此人" << endl;
    }
    system("pause"); //按任意键继续
    system("cls");
}

void cleanperson(Addressbooks *abs)
{
    abs->size = 0;
    cout << "已清空" << endl;
    system("pause");
}

void showMenu()
{
    cout << "**********************" << endl;
    cout << "*****1.添加联系人*****" << endl;
    cout << "*****2.显示联系人*****" << endl;
    cout << "*****3.删除联系人*****" << endl;
    cout << "*****4.查找联系人*****" << endl;
    cout << "*****5.修改联系人*****" << endl;
    cout << "*****6.清空联系人*****" << endl;
    cout << "*****0.退出通讯录*****" << endl;
    cout << "**********************" << endl;
}

int main()
{
    int select;
    Addressbooks abs;
    abs.size = 0;

    while (true)
    {
        showMenu();
        cin >> select;
        switch (select)
        {
        case 1: //添加联系人
            addperson(&abs);
            break;
        case 2:
            showperson(&abs);
            break;
        case 3:
            deleteperson(&abs);
            break;
        case 4:
            findperson(&abs);
            break;
        case 5:
            modifyperson(&abs);
            break;
        case 6:
            cleanperson(&abs);
            break;
        case 0:
            cout << "欢迎下次使用" << endl;
            system("pause");
            return 0;
            break;
        default:
            break;
        }
    }
    system("pause");
    return 0;
}
