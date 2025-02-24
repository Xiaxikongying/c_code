// hai zei oj 284
/*
 超市里有N个商品. 第i个商品必须在保质期之前卖掉, 若卖掉可让超市获得pi的利润.
​ 每天只能卖一个商品.现在你要让超市获得最大的利润.

输入
​每组数据第一行为一个整数N(0<N≤10000)
即超市的商品数目之后N行，每行各有两个整数, 第i行为pi,di(1<=pi,di<=10000)
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct Data
{
    int p; //利润
    int d; //过期日期
    Data(int p, int d) : p(p), d(d) {}

    bool operator<(const Data &obj) const
    {
        if (d != obj.d)
            return d < obj.d;
        return p > obj.p;
    }
};

typedef pair<int, int> PII; //利润 编号

int main()
{
    int n;
    cin >> n;
    vector<Data> arr;
    set<PII> s;
    for (int i = 0, p, d; i < n; i++)
    {
        cin >> p >> d;
        arr.push_back(Data(p, d));
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        if (arr[i].d > s.size())
            s.insert(PII(arr[i].p, i));

        else if (arr[i].d == s.size())
        { //同一个过期日期的商品只能有一个
            if (arr[i].p > s.begin()->first)
            {
                s.erase(s.begin());
                s.insert(PII(arr[i].p, i));
            }
        }
    }
    int ans = 0;
    for (auto x : s)
    {
        ans += x.first;
        
    }
    cout << ans << endl;
    /*
     cout << endl;
     for (int i = 0; i < n; i++)
     {
         cout << i << ": " << arr[i].p << " " << arr[i].d << endl;
     }
     */

    system("pause");
    return 0;
}