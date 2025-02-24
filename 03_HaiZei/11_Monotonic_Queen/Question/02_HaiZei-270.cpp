#include <iostream>
#include <deque>
#include <vector>
using namespace std;

// hai zei oj 270
int main()
{
    int n, m;
    cin >> n >> m;
    deque<int> q;
    vector<int> s(n + 1);

    s[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
        s[i] += s[i - 1];
        //s[i] 表示前i位的和    
        //s[0] = 0    s[5] - s[1] == 2 + 3 + 4 +5 即4位数的和
    }

    q.push_back(0); //压入的是下标  第0为的值为0
    unsigned int a = -1;
    int ans = 0 - (int)(a / 2) - 1;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, s[i] - s[q.front()]);
        while (!q.empty() && s[q.back()] > s[i])
        {
            q.pop_back();
        }
        q.push_back(i);
        if (i == q.front() + m)
            q.pop_front();
    }
    cout << ans << endl;

    system("pause");
    return 0;
}