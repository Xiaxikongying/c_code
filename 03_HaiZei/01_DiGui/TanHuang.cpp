#include <iostream>
#include <vector>
using namespace std;

/*
有一个小球掉落在一串连续的弹簧板上，小球落到某一个弹簧板后，会被弹到某一个地点，直到小球被弹到弹簧板以外的地方。

假设有 n个连续的弹簧板，每个弹簧板占一个单位距离，a[i]代表代表第 i个弹簧板会把小球向前弹 a[i]个距离。比如位置 1的弹簧能让小球前进 2个距离到达位置 3。

如果小球落到某个弹簧板后，经过一系列弹跳会被弹出弹簧板，那么小球就能从这个弹簧板弹出来。

现在小球掉到了1号弹簧板上面，那么这个小球会被弹起多少次，才会弹出弹簧板。
1号弹簧板也算一次

样例
5
2 2 3 1 2
输出：2

*/

int tan(int i, vector<int> &arr,int n)  //i 表示当前小球的位置
{
    if(i>=n)
        return 0;
    else
        return tan(i + arr[i], arr, n)+1;
        //此处的+1 是每次递归一次tan() 就记一次 记录递归的次数 最后tan()会return为0
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0, a; i < n; i++)
    {
        cin >> a;
        arr.push_back(a);
    }
    cout << tan(0, arr, n) << endl;
    //system("pause");
    return 0;
}