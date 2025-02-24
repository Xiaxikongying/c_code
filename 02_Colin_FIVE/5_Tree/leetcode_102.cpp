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
#include <vector>
#include <queue>
// leetcode 102 层序遍历
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode *> q;
        TreeNode *t = NULL;
        int cnt = 0;
        q.push(root);

        while (!q.empty())
        {
            vector<int> temp;
            cnt = q.size();
            for (int i = 0; i < cnt; i++)
            {
                t = q.front();
                if (t->left)
                    q.push(t->left);
                if (t->right)
                    q.push(t->right);
                temp.push_back(t->val);
                q.pop();
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

class Solution
{
public:
    void dfs(TreeNode *root, int k, vector<vector<int>> &ans)
    {
        if (root == NULL)
            return;
        if (k == ans.size())
            ans.push_back(vector<int>());
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