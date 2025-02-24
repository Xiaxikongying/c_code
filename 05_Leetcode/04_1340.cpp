class Solution
{
public:
    vector<int> flag, dp;
    int n;
    int maxJumps(vector<int> &arr, int d)
    {
        n = arr.size();
        int min = 1000000;
        for (int i = 0; i < n; i++)
        {
            flag.push_back(0);
            dp.push_back(1);
            if (arr[i] < min)
                min = arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == min) // 最小值的dp已经确定，可以flag也可以确定了
                flag[i] = 1;
        }

        int res = 1;
        for (int i = 0; i < n; i++)
        {
            dp[i] = getval(arr, i, d);
            res = max(res, dp[i]);
        }
        return res;
    }

    int getval(vector<int> &arr, int ind, int d) // 获取ind处的dp
    {
        if (flag[ind]) // 表示已经得到正确的dp值了
            return dp[ind];
        for (int j = 1; j <= d; j++)
        {
            if (ind + j < n && arr[ind] > arr[ind + j])
                dp[ind] = max(dp[ind], getval(arr, ind + j, d) + 1);
            else
                break;
        }
        for (int j = 1; j <= d; j++)
        {
            if (ind - j >= 0 && arr[ind] > arr[ind - j])
                dp[ind] = max(dp[ind], getval(arr, ind - j, d) + 1);
            else
                break;
        }
        flag[ind] = 1;
        return dp[ind];
    }
};