#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
7
2 1 4 5 1 3 3
*/
int main()
{
    int n; //元素个数  窗口大小
    cin >> n;
    vector<int> arr(n + 2, 0);
    vector<int> left(n + 2, 0);
    vector<int> right(n + 2, 0);
    stack<int> s;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    for (int i = 1; i <= n + 1; i++) //取n+1是为了让所有元素出栈 
    {
        while (!s.empty() && arr[s.top()] > arr[i])
        {
            right[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty())
        s.pop();

    for (int i = n; i >= 0; i--) //取0 是为了让全部元素出栈
    {
        while (!s.empty() && arr[s.top()] > arr[i])
        {
            left[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    long long h, l, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        h = arr[i];
        l = right[i] - left[i] - 1;
        ans = max(ans, h * l);
    }
    cout << ans << endl;
    system("pause");
    return 0;
}
