#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;

vector<int> findLargestNumberLessThanN(const string &n, const vector<int> &A)
{
    vector<int> result;
    vector<char> digits;
    for (int num : A)
        digits.push_back(num + '0');
    sort(digits.begin(), digits.end());

    bool flag = false;
    bool found = false; // 用于表示当前层有没有找到选值
    for (int i = 0; i < n.size(); ++i)
    {
        found = false;
        if (flag)
            result.push_back(digits.size() - 1);
        else
        {
            for (int j = digits.size() - 1; j >= 0; --j) // 从最大的数字开始
            {
                if (digits[j] > n[i])
                    continue;
                if (digits[j] == n[i])
                {
                    found = true;
                    result.push_back(j);
                    break;
                }
                if (digits[j] < n[i])
                {
                    flag = true;
                    result.push_back(j);
                    break;
                }
            }

            if (found == false) // 当前层没有找到数字  让上面的层级减少一个选值
            {
                int a = i - 1;
                while (a >= 0)
                {
                    if (result[a] >= 1)
                    {
                        result[a]--;
                        found = true;
                        flag = true;
                        result.push_back(digits.size() - 1);
                        break;
                    }
                    --a;
                }
                if (found == false) // 前面层都不能减少   只能少一位数字
                {
                    vector<int> tres;
                    for (int k = 0; k < n.size() - 1; ++k)
                    {
                        tres.push_back(digits.size() - 1);
                    }
                    return tres;
                }
            }
        }
    }
    return result;
}
int find(vector<int> result, vector<int> A)
{
    int ans = 0;
    int len = result.size();
    for (int i = 0; i < len; i++)
    {
        ans += A[result[i]] * pow(10, len - i - 1);
    }
    return ans;
}
int main()
{
    string n = "2221";
    vector<int> A = {2, 9};
    vector<int> result = findLargestNumberLessThanN(n, A);
    int ans = find(result, A);

    cout << ans << endl;
    system("pause");
    return 0;
}
