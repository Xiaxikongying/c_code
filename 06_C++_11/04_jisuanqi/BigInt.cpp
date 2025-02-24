#include <iostream>
#include <vector>
using namespace std;

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
            if (at(i) < 10 && at(i) > -10)
                continue;
            if (i == size() - 1) // 如果i到了最后一位还是大于10 添加
                push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
        if (at(size() - 1) == 0) // 最后一位为0  删除
            this->pop_back();
        return;
    }

    // 加法
    BigInt &operator+=(const BigInt &a)
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (i > size()) // 当a的位数多于this时，直接移过来
                push_back(a[i]);
            at(i) += a[i];
        }
        proccess_digit(); // 处理进位
        return *this;
    }
    BigInt operator+(const BigInt &a)
    {
        BigInt ret(*this);
        ret += a;
        return ret;
    }

    // 减法
    BigInt &operator-=(const BigInt &a)
    {
        for (int i = 0; i < a.size(); i++)
            at(i) -= a[i];

        proccess_digit(); // 处理进位
        return *this;
    }
    BigInt operator-(const BigInt &a)
    {
        BigInt ret(*this);
        ret -= a;
        return ret;
    }

    // 乘法
    BigInt &operator*=(int x)
    {
        for (int i = 0; i < size(); i++)
            at(i) *= x;
        proccess_digit();
        return *this;
    }
    BigInt operator*(int x)
    {
        BigInt ret(*this);
        ret *= x;
        return ret;
    }

    // 大整数相乘
    BigInt &operator*=(BigInt x)
    {
        int n = this->size();
        int m = x.size();
        int mul, sum;

        BigInt res;
        res.resize(n + m - 1, 0);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                mul = at(i) * x[j];
                sum = mul + res[i + j];     // 加上进位
                res[i + j + 1] += sum / 10; // 进位
                res[i + j] = sum % 10;
            }
        }
        *this = res;
        return *this;
    }
    BigInt operator*(BigInt x)
    {
        BigInt res(*this);
        res *= x;
        return res;
    }
};

ostream &operator<<(ostream &out, const BigInt &a)
{
    out << a[a.size() - 1];
    for (int i = a.size() - 2; i >= 0; i--)
    {
        out << abs(a[i]);
    }

    cout << endl;
    return out;
}

int main()
{
    /*
    BigInt a(123456);
    BigInt b(235);
     a*= b;
    cout << a << endl;
    cout << a * b << endl;
    */
    BigInt a(-123);
    a += 10;
    cout << a << endl;
    BigInt b(200);
    a += b;
    cout << a << endl;
    system("pause");
    return 0;
}