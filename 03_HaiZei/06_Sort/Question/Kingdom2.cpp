#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// haizei oj 256 国王游戏
/*
输入
第一行包含一个整数 n，表示大臣的人数第二行包含两个整数 a 和 b，之间用一个空格隔开,分别表示国王左手和右手上的整数。 (均小于 10000)
接下来 n行，每行包含两个整数 a和b，之间用一个空格隔开，分别表示每个大臣左手和右手上的整数。(均小于 10000)输出
输出
一个整数，表示重新排列后的队伍中获奖赏最多的大臣所获得的金币数。
*/

class BigInt : public vector<int>
{
public:
    BigInt(int x) // 1234 ---> [4,3,2,1]
    {
        this->push_back(x);
        process_digit();//处理进位
        return;
    }

    void process_digit()
    {
        for (int i = 0; i < size(); i++)
        {
            if (at(i) < 10)
                continue;
            else
            {
                if (i + 1 == size())
                    this->push_back(0);
                at(i + 1) += at(i) / 10;
                at(i) %= 10;
            }
        }

        while (size() > 1 && at(size() - 1) == 0)
            this->pop_back();
        return;
    }

    void operator*=(int x)
    {
        for (int i = 0; i < size(); i++)
            at(i) *= x;
        process_digit();
        return;
    }

    BigInt operator/(int x)
    {
        BigInt ret(*this);
        int y = 0;
        for (int i = size() - 1; i >= 0; i--)
        {
            y = y * 10 + at(i);
            ret[i] = y / x;
            y %= x;
        }
        ret.process_digit();
        return ret;
    }

    bool operator>(const BigInt &a) const
    {
        if (size() != a.size())
            return size() > a.size();
        for (int i = size() - 1; i >= 0; i--)
        {
            if (at(i) != a[i])
                return at(i) > a[i];
        }
        return false;
    }
};

ostream &operator<<(ostream &out, const BigInt &a)
{
    for (int i = a.size() - 1; i >= 0; i--)
    {
        out << a[i];
    }
    return out;
}

#define MAX_N 1000
int a[MAX_N + 5]; //左手
int b[MAX_N + 5]; //右手
int ind[MAX_N + 5];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) // 1个国王 + n个大臣
    {
        cin >> a[i] >> b[i];
        ind[i] = i;
    }

    sort(ind + 1, ind + n + 1, [&](int i, int j) -> bool
         { return a[i] * b[i] < a[j] * b[j]; });

    BigInt p = a[0];
    BigInt ans = 0, temp = 0;
    for (int i = 1; i <= n; i++)
    {
        temp = p / b[ind[i]];
        if (temp > ans)
            ans = temp;
        p *= a[ind[i]];
    }
    cout << ans << endl;

    system("pause");
    return 0;
}
