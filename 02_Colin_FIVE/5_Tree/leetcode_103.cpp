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
// leetcode 103  锯齿形层序遍历

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode *> q;
        TreeNode *t = NULL;
        int cnt = 0;
        q.push(root);
        int flag = 0;
        while (!q.empty())
        {
            flag++;
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
            if (flag % 2 == 0)
            {
                for (int i = 0, j = temp.size() - 1; i < j; i++, j--)
                    swap(temp[i], temp[j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};