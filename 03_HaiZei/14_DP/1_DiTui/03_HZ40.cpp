#include <iostream>
#include <vector>
using namespace std;
// haizeioj 40 爬楼梯
/*
8 200
1 2 5 10 20 50 100 200
3871
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
            if (at(i) < 0)
            {
                at(i + 1) -= 1;
                at(i) += 10;
            }
            if (at(i) < 10)
                continue;
            if (i == size() - 1) //如果i到了最后一位还是大于10 添加
                push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
        if(at(size()-1) == 0)
            this->pop_back();
        return;
    }

    BigInt &operator+=(const BigInt &a)
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (i > size()) //当a的位数多于this时，直接移过来
                push_back(a[i]);
            at(i) += a[i];
        }
        proccess_digit(); //处理进位
        return *this;
    }

    BigInt operator+(const BigInt &a)
    {
        BigInt ret(*this);
        ret += a;
        return ret;
    }

    BigInt &operator-=(const BigInt &a)
    {
        for (int i = 0; i < a.size(); i++)
            at(i) -= a[i];
        
        proccess_digit(); //处理进位
        return *this;
    }

    BigInt operator-(const BigInt &a)
    {
        BigInt ret(*this);
        ret -= a;
        return ret;
    }
};

ostream &operator<<(ostream &out, const BigInt &a)
{
    for (int i = a.size() - 1; i >= 0; i--)
    {
        out << a[i];
    }
    cout << endl;
    return out;
}

int main()
{
    /*
    int n;
    BigInt f[505] = {0};
    cin >> n;
    f[0] = 1;
    f[2] = 1;
    f[3] = 1;
    for (int i = 4; i <= n; i++)
    {
        f[i] = f[i - 2] + f[i - 3];
    }
    cout << f[n] << endl;
*/

    BigInt a(23);
    BigInt b(11);
    cout << a - b << endl;
    system("pause");
    return 0;
}
