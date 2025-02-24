#include <iostream>
#include <algorithm>
#include <vector>
#include "sort_Test.h"
using namespace std;

struct Data
{
    int x, y;
};

void output(int *arr, int n)
{
    printf("arr[%d] = ", n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return;
}

void output(vector<int> &arr)
{
    printf("vector arr[%lu] = ", arr.size());
    for (int i = 0; i < arr.size(); i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return;
}

void output(vector<Data> &arr)
{
    printf("vector mydata arr[%lu] = ", arr.size());
    for (int i = 0; i < arr.size(); i++)
    {
        printf("(%d , %d) ", arr[i].x, arr[i].y);
    }
    printf("\n");
    return;
}

bool cmp1(int a,int b)
{
    return (a > b); //如果 a>b  a在b前  从大到小
}
void test01()
{
    // sort  array
    int *arr = getRandData(10);
    output(arr, 10);
    sort(arr, arr + 10); //默认从小到大
    output(arr, 10);

    sort(arr, arr + 10, greater<int>()); //从大到小
    sort(arr, arr + 10, cmp1);
    output(arr, 10);
}

void test02()
{
    // sort vector
    vector<int> arr;
    for (int i = 0; i < 10; i++)
        arr.push_back(rand() % 10000);

    output(arr);
    sort(arr.begin(), arr.end());
    output(arr);

    sort(arr.begin(), arr.end(), greater<int>());
    output(arr);
}

bool cmp(const Data &a, const Data &b)
{
    if (a.x != b.x)
        return a.x < b.x; //如果 a.x < b.x 成立 a排在b前面 
    return a.y < b.y;     //如果 a.y < b.y 成立 a排在b前面
}

void test03()
{
    // sort mydata
    vector<Data> arr;
    for (int i = 0; i < 10; i++)
    {
        Data d;
        d.x = rand() % 10;
        d.y = rand() % 10;
        arr.push_back(d);
    }
    output(arr);
    sort(arr.begin(), arr.end(), cmp);
    output(arr);
}

void test04()
{
    // sort ind
    int *arr = getRandData(10);
    int *ind = getRandData(10);
    for (int i = 0; i < 10; i++)
        ind[i] = i;
    output(arr, 10);

    sort(ind, ind + 10, [&](int a, int b) -> bool
         { return arr[a] < arr[b]; });
    output(arr, 10);
    output(ind, 10);
}

int main()
{
    test01();
    printf("\n\n");
    //test02();
    printf("\n\n");
    //test03();
    printf("\n\n");
   //test04();

    system("pause");
    return 0;
}