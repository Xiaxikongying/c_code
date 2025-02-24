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

// leetcode 105
//给出前序遍历和中序遍历  求二叉树
class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if (preorder.size() == 0)
            return NULL;
        int pos = 0;             //中序根节点的位置
        int n = preorder.size(); //节点个数
        while (inoreder[pos] != preorder[0])
            pos++;
        TreeNode *root = new TreeNode(preorder[0]);

        vector<int> preArr, inArr;
        for (int i = 1; i <= pos; i++)
            preArr.push_back(preorder[i]); //左子树前序遍历
        for (int i = 0; i < pos; i++)
            inArr.push_back(inorder[i]); //左子树中序遍历
        root->left = buildTree(preArr, inArr);
        preArr.clear();
        inArr.clear(); 

        for (int i = pos + 1; i < n; i++)
            preArr.push_back(preorder[i]); //右子树前序遍历
        for (int i = pos + 1; i < n; i++)
            inArr.push_back(inorder[i]); //右子树中序
        root->right = buildTree(preArr, inArr);

        return root;
    }
};