#include <iostream>
#include <vector>
using namespace std;
/*
汉诺塔问题
2---->6
8---->510
*/

class BigInt : public vector<int>
{
public:
    BigInt() { push_back(0); }
    BigInt(int x)
    {
        push_back(x);
        process_digit();
    }

    void process_digit()
    {
        for (int i = 0; i < size(); i++)
        {
            if (at(i) < 10)
                continue;
            if (i + 1 == size())
                push_back(0);
            at(i + 1) += at(i) / 10;
            at(i) %= 10;
        }
    }

    BigInt operator*(int x)
    {
        BigInt ret(*this);
        for (int i = 0; i < size(); i++)
            ret[i] = at(i) * x;
        
        ret.process_digit();
        return ret;
    }

    BigInt operator+(int x)
    {
        at(0) += x;
        process_digit();
        return *this;
    }
};
ostream &operator<<(ostream &out, const BigInt &a)
{
    for (int i = a.size() - 1; i >= 0; i--)
        out << a[i];
    return out;
}

BigInt f[205] = {0};

int main()
{
    int n;
    cin >> n;
    f[1] = 2;
    for (int i = 2; i <= n; i++)
    {
        f[i] = f[i - 1] * 2 + 2;
    }

    cout << f[1] << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << f[i] << "  ";
    }
    cout << endl;
    system("pause");
    return 0;
}
