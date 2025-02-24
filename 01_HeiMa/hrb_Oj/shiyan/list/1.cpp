#include <iostream>
using namespace std;

#define max 1000

struct sqlist
{
    int a[max]; //用于存储数据
    int n;      //总数
};

void insertlist(sqlist &list, int i, int x)
{
    if (list.n + 1 > max)
        cout << "线性表已满" << endl;
    else if (i < 1 || i > list.n + 1)
        cout << "插入位置有误" << endl;
    else
    {
        for (int j = list.n - 1; j >= i - 1; j--)
        {
            list.a[j + 1] = list.a[j];
        }
        list.n++;
        list.a[i - 1] = x;
    }
}

void deletelist(sqlist &list, int i, int &y)
{
    if (i < 1 || i > list.n + 1)
        cout << "插入位置有误" << endl;
    else
    {
        y = list.a[i - 1];
        for (int j = i; j < list.n; j++)
        {
            list.a[j - 1] = list.a[j];
        }
        list.n = list.n - 1;
    }
}

int main()
{
    int y;
    sqlist list = {{1, 2, 3, 4}, 4};
    cout << "插入前" << endl;
    for (int i = 0; i < list.n; i++)
        cout << list.a[i] << " ";
    cout << endl;
    insertlist(list, 2, 10);
    cout << "插入后" << endl;
    for (int i = 0; i < list.n; i++)
        cout << list.a[i] << " ";
    cout << endl;
    deletelist(list, 4, y);
    cout << "删除后" << endl;

    for (int i = 0; i < list.n; i++)
        cout << list.a[i] << " ";
    cout << endl;

    cout << "删除的位置是" << y << endl;
    system("pause");
    return 0;
}