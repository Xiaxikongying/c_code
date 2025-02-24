#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

// 1.赋值
void test01()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);
    
    vector<int> v2;
    // v2 = v1;
    //或者
    v2.assign(v1.begin(), v1.end());

    vector<int> v3;
    v3.assign(10, 100);
}

//------------------------------------------------------------------------------------------------------------

// 2.容量和大小
void test02()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    cout << v1.empty() << endl; // v1为空返回true

    // size 是容器中元素的个数    capacity是容器的容量
    // capacity 始终 >= size
    cout << v1.capacity() << endl;
    cout << v1.size() << endl;

    v1.resize(15); //将size变为15  不够的用0来填充
    printVector(v1);
    v1.resize(20, 1); //也可以自行指定
    printVector(v1);
}

//---------------------------------------------------------------------------------------------------------------------------

// 3.插入和删除
void test03()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    //尾删
    v1.pop_back(); //删除尾部元素
    printVector(v1);

    //插入
    //第一个参数一定是迭代器
    v1.insert(v1.begin(), 9);
    printVector(v1);
    v1.insert(v1.begin(), 2, 9);
    printVector(v1);

    //删除
    v1.erase(v1.begin());
    v1.erase(v1.begin(), v1.end()); //清空
    v1.clear();                     //也是清空
}

//---------------------------------------------------------------------------------------------------------------------------

// 4.数据存取
void test04()
{
    //访问元素
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
        //或者
        // cout << v1.at(i) << " ";
    }
    cout << endl;

    cout << v1.front() << endl; //容中第一个元素
    cout << v1.back() << endl;  //容中最后一个个元素
}

//---------------------------------------------------------------------------------------------------------------------------

// 5.互换函数
void test05()
{
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(20 - i);
    }
    cout << "交换前：" << endl;
    printVector(v1);
    printVector(v2);

    v1.swap(v2);
    cout << "交换后：" << endl;
    printVector(v1);
    printVector(v2);
}

//---------------------------------------------------------------------------------------------------------------------------

// 6.预留空间
void test06()
{
    int *p = NULL;
    int num1 = 0;
    int num2 = 0;
    vector<int> v1;
    vector<int> v2;
    //当数据过大时，容器会不断扩展空间，比较耗时间
    for (int i = 0; i < 100000; i++)
    {
        v1.push_back(i);
        if (p != &v1[0])
        {
            p = &v1[0];
            num1++;
        }
    }
    cout << num1 << endl;

    //但如果提前预留空间 就不会有这样的问题
    v2.reserve(100000);
    for (int i = 0; i < 100000; i++)
    {
        v2.push_back(i);
        if (p != &v2[0])
        {
            p = &v2[0];
            num2++;
        }
    }
    cout << num2 << endl;
}

int main()
{
    test01();
    system("pause");
}