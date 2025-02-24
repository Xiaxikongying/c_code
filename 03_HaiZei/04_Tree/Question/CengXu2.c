// leetcode 102
//层序遍历  dfs写法

class Solution
{
public:
    void dfs(TreeNode *root, int k, vector<vector<int>> &ans)
    {
        if (root == NULL)
            return;
        if (k == ans.size())
            ans.push_back (vector<int>());
        ans[k].push_back(root->val);
        dfs(root->left, k + 1, ans);
        dfs(root->right, k + 1, ans);
        return;
    }

    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        dfs(root, 0, ans);
        return ans;
    }
};