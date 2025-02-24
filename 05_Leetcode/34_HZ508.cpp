#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int brige(vector<int> &vec, int right)
{
    if (right < 0) // 没有人
        return 0;
    if (right == 0) // 一个人
        return vec[0];
    if (right == 1) // 两个人
        return vec[1];
    if (right == 2) // 三个人
        return vec[0] * 2 + vec[2];
    // 剩余人数大于2
    int val = 0;
    if (vec[1] * 2 < vec[right - 1] + vec[0])
    {
        val = vec[0] + vec[1] * 2 + vec[right];
        return val + brige(vec, right - 2);
    }
    else
    {
        val = vec[0] * 2 + vec[right - 1] + vec[right];
        return val + brige(vec, right - 2);
    }
}

int main()
{
    int n, ans = 0;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    sort(vec.begin(), vec.end());
    cout << brige(vec, vec.size() - 1) << endl;
    system("pause");
    return 0;
}
