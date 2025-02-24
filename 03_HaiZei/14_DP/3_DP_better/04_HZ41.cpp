#include <iostream>
using namespace std;

/*
5 3---30
19 3---524286

本题是对墙壁涂色(HZOJ_41)的再次优化 ----->优化二
那有没有方法可以使得dp成为一维数组呢？
我们可以将dp[n] 的方法数 可以按照倒数第二来分--->即 第n-1块
若第n-1块 与 第一块 颜色不同---->这种情况不就符合dp[n-1]的定义吗
                              所以方法数 = dp[n-1] * (k-2)  --->(k-2)表示剩余颜色数量
                              (n块颜色不能与n-1相同，也不能与 1 相同)

若第n-1块 与 第一块 颜色相同---->则倒数第三块（n-2） 与第一块颜色不同,也符合dp的定义----->dp[n-2] * (k-1)

若想要用这个公式，则需要满足 n-2 与 第一块 不可以是同一块
也就是说，最少需要四块墙壁，才可以使用改公式

所以dp[n] = dp[n] = (k-1)*dp[n-2] + (k-2)*dp[n-1]
 */

int f[1005] = {0};
int main()
{
    int n, k; //墙的数量   颜色种数
    cin >> n >> k;

    f[1] = k;
    f[2] = k * (k - 1);
    f[3] = k * (k - 1) * (k - 2);
    for (int i = 4; i <= n; i++) //遍历每一种墙壁数量
        f[i] = (k - 1) * f[i - 2] + (k - 2) * f[i - 1];

    cout << f[n] << endl;
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

BigInt f[1005] = {0};
int main()
{
    int n, k; //墙的数量   颜色种数
    cin >> n >> k;

    f[1] = k;
    f[2] = k * (k - 1);
    f[3] = k * (k - 1) * (k - 2);
    for (int i = 4; i <= n; i++) //遍历每一种墙壁数量
        f[i] = f[i - 2] * (k - 1) + f[i - 1] * (k - 2);

    cout << f[n] << endl;
    return 0;
}

*/