// hai zei oj 287
//合并果子
//输入  3
//      1 2 9
//输出  15

#include <iostream>
#include <set>
using namespace std;

typedef pair<int, int> PII;

int main()
{

    // set 中的数据始终从小到大排序 不允许插入相同的元素
    //但是multiset可以有重复的

    /*
    set<pair<int, int>> s;
    s.insert(pair<int, int>(10, 1));
    cout << s.begin()->first << ", " << s.size() << endl;
    s.insert(pair<int, int>(8, 2));
    cout << s.begin()->first << ", " << s.size() << endl;
    s.insert(pair<int, int>(9, 3));
    cout << s.begin()->first << ", " << s.size() << endl;
    s.insert(pair<int, int>(9, 4));
    cout << s.begin()->first << ", " << s.size() << endl;
    */

    set<PII> s;
    int n;
    cin >> n;
    for (int i = 0, a; i < n; i++)
    {
        cin >> a;
        s.insert(PII(a, i));
    }
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        int a = s.begin()->first;
        s.erase(s.begin());
        int b = s.begin()->first;
        s.erase(s.begin());
        // a b 是数量最小的果子
        s.insert(PII(a + b, n + i));
        ans += a + b;
    }
    cout << ans << endl;

    system("pause");
    return 0;
}