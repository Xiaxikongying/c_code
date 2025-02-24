#include <iostream>
using namespace std;

/*
5 3---30
19 3---524286

本题是对墙壁涂色(HZOJ_41)的优化  假设第一个墙壁的颜色为1
因为方案的数量与颜色的种类无关
所以我们只需要求一个分支，即第一面墙的颜色为1
然后将求得的方法数 * 总颜色数量就可以了
所以只需要一个二维数组记录 墙壁数量  最后一面墙壁的颜色
*/

int f[1005][11] = {0};
int main()
{
    int n, k; //墙的数量   颜色种数
    cin >> n >> k; 

    f[1][1] = 1;                 //假设第一块墙壁颜色为1
    for (int N = 2; N <= n; N++) //遍历每一种墙壁数量
    {
        for (int i = 1; i <= k; i++) //遍历最后一块墙壁每一种颜色
        {
            for (int j = 1; j <= k; j++) //f[N] = 累加f[N-1]
            {
                if (i == j)
                    continue;
                f[N][i] += f[N - 1][j];
            }
        }
    }

    int ans = 0;
    for (int i = 2; i <= k; i++) //不加上f[n][1]
        ans += f[n][i];

    cout << ans * k << endl;
    system("pause");
    return 0;
}
/*

#include <iostream>
#include <vector>
using namespace std;
// haizeioj 41 墙壁涂色

class BigInt : public vector<int>
{
public:
    BigInt() { push_back(0); }
    BigInt(int x)
    {
        this->push_back(x);
        proccess_digit();
    }

    void proccess_digit()
    {
        for (int i = 0; i < size(); i++)
        {
            if (at(i) < 100000)
                continue;
            if (i == size() - 1)
                push_back(0);
            at(i + 1) += at(i) / 100000;
            at(i) %= 100000;
        }
    }

    BigInt &operator+=(const BigInt &a)
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (i < size())
                at(i) += a[i];
            else
                push_back(a[i]);
        }
        proccess_digit();
        return *this;
    }

    BigInt operator+(const BigInt &a)
    {
        BigInt ret(*this);
        ret += a;
        return ret;
    }

    BigInt operator*(int a)
    {
        BigInt ret(*this);
        for (int i = 0; i < ret.size(); i++)
            ret[i] *= a;

        ret.proccess_digit();
        return ret;
    }
};

ostream &operator<<(ostream &out, const BigInt &a)
{
    out << a[a.size() - 1];
    for (int i = int(a.size()) - 2; i >= 0; i--)
    {
        if (a[i] >= 10000)
            out << a[i];
        else
        {
            for (int j = 10000; j > 0; j /= 10) //防止 12 03456----> 12 3456  确保每一位都输出
                out << a[i] % (j * 10) / j;     //一位一位的输出，确保后面的一定有5位
        }
    }
    return out;
}

//本题是对墙壁涂色的优化  假设第一个墙壁的颜色为1
BigInt f[1005][11] = {0};
int main()
{
    int n, k; //墙的数量   颜色种数
    cin >> n >> k;

    f[1][1] = 1;                 //假设第一块墙壁颜色为1
    for (int N = 2; N <= n; N++) //遍历每一种墙壁数量
    {
        for (int i = 1; i <= k; i++) //遍历最后一块块墙壁每一种颜色
        {
            f[N][i] = 0;
            for (int l = 1; l <= k; l++)
            {
                if (i == l)
                    continue;
                f[N][i] += f[N - 1][l];
            }
        }
    }

    BigInt ans = 0;
    for (int i = 2; i <= k; i++) //不加上f[n][1]
        ans += f[n][i];

    cout << ans * k << endl;
    system("pause");
    return 0;
}
*/