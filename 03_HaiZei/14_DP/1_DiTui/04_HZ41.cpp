#include <iostream>
#include <vector>
using namespace std;
// haizeioj 41 墙壁涂色
/*
环形墙壁   相邻两块墙壁颜色相同
5 3
30
*/
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

    BigInt &operator+(const BigInt &a)
    {
        (*this) += a;
        return *this;
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

/*
12 03456 / 100000 = 12
12 03456 % 100000 = 03456 = 3456
*/

BigInt f[1005][11][11] = {0}; // f[i][j][k]  表示有i块墙壁  第一块涂j  最后一块涂k  的方法数
int main()
{
    int n, k; //墙的数量   颜色种数
    cin >> n >> k;
    for (int i = 1; i <= k; i++) //边界条件  当只有一块墙壁时，只能涂一种颜色，
        f[1][i][i] = 1;

    for (int N = 2; N <= n; N++) //遍历每一种墙壁数量
    {
        for (int i = 1; i <= k; i++) //遍历第一块墙壁每一种颜色
        {
            for (int j = 1; j <= k; j++) //遍历最后一块块墙壁每一种颜色
            {
                f[N][i][j] = 0;
                for (int l = 1; l <= k; l++)
                {
                    if (l == j)
                        continue;
                    f[N][i][j] += f[N - 1][i][l];
                }
            }
        }
    }

    BigInt ans = 0;
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i != j)
                ans += f[n][i][j];
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}
