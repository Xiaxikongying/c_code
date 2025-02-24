#include <iostream>
#include <vector>
#include <deque>
using namespace std;

/*
5
3 1 5 2 4
5 2 4 3 1
*/

int main()
{
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    deque<int> qa;
    deque<int> qb;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        //维护两个个单调队列
        while (!qa.empty() && a[i] <= a[qa.back()])
            qa.pop_back();
        qa.push_back(i);

        while (!qb.empty() && b[i] <= b[qb.back()])
            qb.pop_back();
        qb.push_back(i);

        if (qa.front() == qb.front() && qa.size() == qb.size())
            ans++;
        else
            break;
    }
    cout << ans << endl;
    system("pause");
    return 0;
}
