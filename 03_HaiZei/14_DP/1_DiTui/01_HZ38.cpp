#include <iostream>
#include <vector>
using namespace std;
// haizeioj 38
//年龄为2个月的兔子成年
/*
月：1  2  3  4  5  6
成：1  1  2  3  5  8
未：0  1  1  2  3  5

成 = 上月成 + 上月未
为 = 上月成
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
            if (at(i) < 10)
                continue;
            if (i == size() - 1)
                push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
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

BigInt ans[100];

int main()
{
    ans[1] = 1;
    ans[2] = 2;
    int n;

    cin >> n;
    for (int i = 3; i <= n; i++)
        ans[i] = ans[i - 1] + ans[i - 2];

    cout << ans[n];

    system("pause");
    return 0;
}
