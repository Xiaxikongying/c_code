#include <iostream>
#include <deque>
#include <vector>
using namespace std;


//hai zei oj 271
int main()
{
    int n; //序列的长度
    int k; //窗口的长度
    cin >> n >> k;
    vector<int> arr;
    deque<int> q1; //双端队列
    deque<int> q2;
    for (int i = 0, a; i < n; i++)
    {
        cin >> a;
        arr.push_back(a);
    }

    //第一行为窗口在各个位置时的极小值，
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        while (!q1.empty() && arr[q1.back()] > arr[i])
        {
            q1.pop_back();
        }
        q1.push_back(i);
        if (i - q1.front() == k)
            q1.pop_front();

        if (i >= k - 1)
        {
            if (flag == 0)
                flag = 1;
            else
                printf(" ");
            printf("%d", arr[q1.front()]);
        }
    }
    printf("\n");

    //第二行为窗口在各个位置时的极大值。 
    flag = 0;
    for (int i = 0; i < n; i++)
    {
        while (!q2.empty() && arr[q2.back()] < arr[i])
        {
            q2.pop_back();
        }
        q2.push_back(i);
        if (i - q2.front() == k)
            q2.pop_front();
        
        if (i >= k - 1)
        {
            if(flag==0)
                flag = 1;
            else
                printf(" ");
            printf("%d", arr[q2.front()]);
        }
    }
    printf("\n");

    system("pause");
    return 0;
}
/*

#include <iostream>
#include <vector>
#include <deque>
using namespace std;
//8 3
//1 3 -1 -3 5 3 6 7
int main()
{
    int n, k; //元素个数  窗口大小
    cin >> n >> k;
    vector<int> arr(n);
    deque<int> q;
    vector<int> max(n);
    vector<int> min(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        while (!q.empty() && arr[q.back()] < arr[i])
            q.pop_back();
        q.push_back(i);

        if (k == i - q.front())
            q.pop_front();
        if (i >= k - 1)
            max[cnt++] = arr[q.front()];
    }

    q.clear();
    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        while (!q.empty() && arr[q.back()] > arr[i])
            q.pop_back();
        q.push_back(i);

        if (k == i - q.front())
            q.pop_front();
        if (i >= k - 1)
            min[cnt++] = arr[q.front()];
    }

    for (int i = 0; i < cnt; i++)
    {
        if (i)
            cout << " " << min[i];
        else
            cout << min[i];
    }
    cout << endl;

    for (int i = 0; i < cnt; i++)
    {
        if (i)
            cout << " " << max[i];
        else
            cout << max[i];
    }
    cout << endl;

    system("pause");
    return 0;
}

*/