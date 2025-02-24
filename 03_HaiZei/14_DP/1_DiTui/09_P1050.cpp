#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

/*
1923 2
20
*/
class BigInt : public vector<int>
{
public:
    static int MaxLen;
    //由于大数字后K位的是否循环只取决于后k位是什么，与高位无关
    //所以，我们只保留后k位

    BigInt() { push_back(0); }
    BigInt(int n, int v) : vector<int>(n, v) {}
    BigInt(int x)
    {
        push_back(x);
        proccess_digit();
        return;
    }
    BigInt(string &s, int k)
    {
        for (int i = 0, j = s.size() - 1; i < k; i++, j--)
            push_back(s[j] - '0'); //将ascii码转换为 十进制数字
        return;
    }

    void proccess_digit()
    {
        for (int i = 0; i < size(); i++)
        {
            if (at(i) < 10)
                continue;
            if (i + 1 < MaxLen) //说明进位 到了有效位上
            {
                if (i == size() - 1)
                    push_back(0);
                at(i + 1) += at(i) / 10;
            }
            at(i) %= 10;
            if (i >= MaxLen)
                break;
        }
        return;
    }

    BigInt operator*(const BigInt &a)
    {
        BigInt ret(min(MaxLen, int(size() + a.size() - 1)), 0);
        for (int i = 0; i < size(); i++)
        {
            for (int j = 0; j < a.size(); j++)
            {
                if (i + j >= MaxLen)
                    continue;
                ret[i + j] += at(i) * a[j];
            }
        }
        ret.proccess_digit();
        return ret;
    }

    BigInt operator*=(int a)
    {
        for (int i = 0; i < size(); i++)
            at(i) *= a;
        proccess_digit();
        return *this;
    }
};

int BigInt::MaxLen = 0;

ostream &operator<<(ostream &out, const BigInt &a)
{
    for (int i = a.size() - 1; i >= 0; i--)
        out << a[i];
    out << endl;
    return out;
}

int main01()
{
    string s;
    int k;
    cin >> s;
    cin >> k;
    BigInt::MaxLen = k;
    BigInt n(s, k); //记录给出数据的后K位  s是string
    BigInt ans = 1; //记录答案
    BigInt y = n, x = n;
    int cnt;

    for (int i = 0; i < n.size(); i++) //先求个位的循环  十位的循环..... 然后将它们相乘
    {
        cnt = 1;
        while ((y * n).at(i) != n[i])
        {
            y = y * x;
            cnt += 1;
            if (cnt == 11) //超出循环范围
            {
                cout << -1 << endl;
                return 0;
            }
        }

        x = y; //更新x --->即保证个位相同的情况下更新十位（第一次跟新，后面递推即可）
        ans *= cnt;
    }
    cout << ans << endl;
    system("pause");
    return 0;
}

//小数据测试
int main()
{
    int n, k;
    cin >> n >> k;
    int x, y, base = 1;
    base *= pow(10, k); // base 用于取得n的后k位

    x = n % base; // x表示n的后k位
    y = x;        // y表示n的后k位 * n的后k位 i次方

    int cnt = 1;
    while (y * x % base != x)
    {
        y = y * x % base;
        cnt += 1;
    }

    cout << cnt << endl;
    system("pause");
    return 0;
}
