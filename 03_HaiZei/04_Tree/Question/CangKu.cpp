#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

// hai zei oj 245 仓库选址
//在坐标上选一个点做仓库 与所有商店的总距离最短

//---*只有在最中间的商店的那个点建立仓库 距离才会最小*-------

/*
输入：5
     1 3 5 6 10
输出  12
*/
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
    sort(arr.begin(), arr.end());
    int p = arr[n / 2];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += abs(arr[i] - p);
    }
    cout << ans << endl;

    system("pause");
    return 0;
}