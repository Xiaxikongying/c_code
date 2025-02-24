#include <iostream>
#include <set>
#include <vector>
using namespace std;

/*
hai zei oj 285
n m 矩阵
每行取一个数字 求前m小的组合的和

样例输入
2 3
1 2 3
2 2 3
输出
3 3 4

*/

int main()
{
    int n, m;
    int t = 0;
    cin >> n >> m;
    multiset<int> s;
    s.insert(0);

    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (auto x : s)
        {
            temp.push_back(x);
        }
        s.clear();

        for (int j = 0, a; j < m; j++)
        {
            cin >> a;
            for (auto x : temp)
            {
                if (s.size() < m || *s.begin() < x - a)
                {
                    s.insert(x - a);
                }
                if (s.size() > m)
                    s.erase(s.begin());
            }
        }
    }
    int flag = 0;
    for (auto iter = s.rbegin(); iter != s.rend(); iter++)
    {
        if (flag)
            cout << " ";
        cout << -*iter;
        flag = 1;
    }
    cout << endl;

    system("pause");
    return 0;
}