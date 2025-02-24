// 方法一
#include <unordered_map>
class Solution
{
public:
    int longestEqualSubarray(vector<int> &nums, int k)
    {
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < nums.size(); i++)
            m[nums[i]].push_back(i);

        int ans = 0;
        for (auto &[_, vec] : m)
        {
            for (int i = 0, j = 0; j < vec.size(); j++)
            {
                while (vec[j] - vec[i] - (j - i) > k)
                    i++;
                ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};
// 方法二
class Solution
{
public:
    int longestEqualSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ans = 0;
        vector<int> flag(n + 1, 0); // 记录每个数字出现的次数
        for (int i = 0, j = 0; j < n; j++)
        {
            flag[nums[j]]++; // num[j]出现次数++
            ans = max(ans, flag[nums[j]]);
            
            while (j - i + 1 - flag[nums[i]] > k)
            {
                flag[nums[i]]--;
                i++;
            }
        }
        return ans;
    }
};
