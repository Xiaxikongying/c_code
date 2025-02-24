#include <iostream>
#include <stack>
using namespace std;

int f(int n)
{
    if (n == 1)
        return 1;
    return n * f(n - 1);
}

struct Data
{
    Data(int n, int *pre_ret) : n(n), pre_ret(pre_ret)
    {
        code = 0;
    }
    int n;
    int code, ret, *pre_ret;
};

int non_f(int n)
{
    stack<Data> s;
    int ans;
    Data d(n, &ans);
    s.push(d);
    while (!s.empty())
    {
        Data &cur = s.top();
        switch (cur.code)
        {
        case 0:
        {
            if (cur.n == 1)
            {
                //这行相当于if(n==1) reeturn 1
                *(cur.pre_ret) = 1;
                s.pop();
            }
            else
            {
                cur.code = 1; //执行状态
            }
        }
        break;

        case 1:
        {
            Data d(cur.n - 1, &cur.ret);
            cur.code = 2; //表示f(n)已经计算完，准备计算n*f(n-1)
            s.push(d);
        }
        break;

        case 2:
        {
            *(cur.pre_ret) = cur.ret * cur.n;
            s.pop();
        }
        break;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    // cout << "f(n):" << f(n) << endl;
    cout << "non_f(n):" << non_f(n) << endl;
    system("pause");
    return 0;
}