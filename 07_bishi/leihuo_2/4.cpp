#include <iostream>
#include <vector>
#include <deque>
using namespace std;

double max_sum = 0; // 总伤害
double max_k = 0;   // 伤害最大时系数
double max_a = 0;   // 伤害最大时数量
deque<double> q;
vector<double> arr;
double n, m;

void cal()
{
    double num = (double)q.size();
    double k = abs(arr[q[0]] - arr[q[num - 1]]);
    if (num < 2)
        k = 180;
    else
    {
        for (double i = 1; i < num; ++i)
            k = min(k, abs(arr[q[i]] - arr[q[i - 1]]));
    }
    double d = 1 / (2 * m) + 1 / (2 * num) - (180 - k) / (360 * m * num);
    d *= num;
    if (d > max_sum)
    {
        max_sum = d;
        max_a = num;
        max_k = k;
    }
    for (int i = 0; i < num; ++i)
    {
        cout << q[i] << " ";
    }
    cout << endl;
}

void dfs(vector<double> &arr, double i, double left, double right)
{
    if (left > right || i >= m)
        return;
    for (double k = left; k <= right; ++k)
    {
        q.push_back(k);
        cal();
        dfs(arr, i + 1, k + 1, right);
        q.pop_back();
    }
}

int main()
{
    cin >> n >> m;
    double t;
    for (double i = 0; i < n; ++i)
    {
        cin >> t;
        arr.push_back(t);
    }

    dfs(arr, 0, 0, n - 1);
    printf("%.5lf\n", max_k);
    cout << max_a << endl;
    system("pause");
    return 0;
}
