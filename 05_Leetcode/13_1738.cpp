class Solution
{
public:
    int kthLargestValue(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> vec(n, vector<int>(m));
        vec[0][0] = matrix[0][0];
        vector<int> ans;
        ans.push_back(vec[0][0]);

        for (int i = 1; i < m; i++)
        {
            vec[0][i] = matrix[0][i] ^ vec[0][i - 1];
            ans.push_back(vec[0][i]);
        }

        for (int i = 1; i < n; i++)
        {
            vec[i][0] = matrix[i][0] ^ vec[i - 1][0];
            ans.push_back(vec[i][0]);
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                vec[i][j] = matrix[i][j] ^ vec[i - 1][j - 1] ^ vec[i - 1][j] ^ vec[i][j - 1];
                ans.push_back(vec[i][j]);
            }
        }
        sort(ans.begin(), ans.end(), greater<int>());
        return ans[k - 1];
    }
};