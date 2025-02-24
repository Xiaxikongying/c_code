#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//过河
/*
船
每条船最多坐两个人
100--->船的承重
9--————>人数
90 20 20 30 50 60 70 80 90
6
*/
int main()
{
    int zhou;
    cin >> zhou;
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());
    int ans = 0;
    int head = 0;
    int tail = n - 1;
    while (head < tail)
    {
        if (arr[head] + arr[tail] <= zhou)
        {
            head += 1;
            tail -= 1;
        }
        else
            tail -= 1;
        ans++;
    }
    if (head == tail)
        ans++;
    cout << ans << endl;

    system("pause");
    return 0;
}