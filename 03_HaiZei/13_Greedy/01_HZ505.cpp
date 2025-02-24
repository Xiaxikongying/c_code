#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

bool cmp(string &a, string &b)
{
    return a + b > b + a; //这里是string  字典序
} //如果true 则不交换两数  若为false 则交换 ---->降序
/*
组合成最大序列
3
132 98 121 
98132121
*/
int main()
{
    int n;
    cin >> n;
    string s;
    vector<string> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        arr.push_back(s);
    }
    sort(arr.begin(), arr.end(), cmp);
    for (int i = 0; i < n;i++)
        cout << arr[i];
    cout << endl;

    system("pause");
    return 0;
}