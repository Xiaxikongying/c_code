/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// leetcode 103 锯齿形层序遍历
//即先从左往右，
//再从右往左进行下一层遍历，以此类推，
//奇数行 从左往右  偶数行 从右往左

class Solution
{
public:

    void dfs(TreeNode *root,int k,vector<vector<int>> &ans)
    {
        if(root== NULL)
            return;
        if(k == ans.size())
            ans.push_back(vector<int>());
        ans[k].push_back(root->val);
        dfs(root->left, k + 1, ans);
        dfs(root->right, k + 1, ans);
        return;
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        dfs(root, 0, ans);
        for (int k = 1; k < ans.size(); k += 2)
        {
            for (int i = 0, j = ans[k].size() - 1; i < j; i++, j--)
            {
                swap(ans[k][i], ans[k][j]);
            }
        }
        return ans;
    }
};

