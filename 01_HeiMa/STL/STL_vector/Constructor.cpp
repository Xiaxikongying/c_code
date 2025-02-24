#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>& v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    //1.
    vector<int> v1;
    for (int i = 0; i < 10;i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    //2.
    vector<int> v2(v1.begin(), v1.end());
    printVector(v2);

    //3.
    vector<int> v3(10, 100);   //10个100
    printVector(v3);

    //4.
    vector<int> v4(v1);
    printVector(v4);
}

int main()
{
    test01();
    system("pause");
}