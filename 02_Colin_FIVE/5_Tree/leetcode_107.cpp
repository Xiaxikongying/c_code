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
//leetcode 107 倒叙层序遍历

class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> ans;
        stack<vector<int>> stack_ans;
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
            stack_ans.push(temp);
        }

        int n = stack_ans.size();
        for (int i = 0; i < n; i++)
        {
            ans.push_back(stack_ans.top());
            stack_ans.pop();
        }
        //或者在102后面将ans头尾swap
        return ans;
    }
};