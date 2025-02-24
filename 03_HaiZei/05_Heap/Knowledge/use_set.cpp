#include <set>
#include <iostream>
using namespace std;

// set 会对元素进行去重处理
//而multiset不会去重
// set 和 multiset 都属于<set>

int main()
{
    cout << "set base usage" << endl;
    set<int> s;
    s.insert(3); // 3
    s.insert(4); // 3 4
    s.insert(2); // 2 3 4
    s.insert(4); // 2 3 4
    cout << s.size() << endl;

    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    for(auto x : s)
    {
        cout << x << " ";
    }
    cout << endl;

    system("pause");
    return 0;
}