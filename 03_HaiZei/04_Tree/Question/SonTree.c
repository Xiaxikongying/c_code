/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//leetcode剑指 Offer 26. 树的子结构  输入两棵二叉树A和B，判断B是不是A的子结构  （即 A 包含 B）
//(约定空树不是任意一个树的子结构)
class Solution
{
public:
    bool match_one(TreeNode *A, TreeNode *B)
    {
        if (A == NULL)
            return B == NULL;
        if (B == NULL)
            return true;

        if (A->val != B->val)
            return false;
        return match_one(A->left, B->left) && match_one(A->right, B->right);
    }

    bool isSubStructure(TreeNode *A, TreeNode *B)
    {
        
        if (A == NULL || B == NULL)
            return false;

        if (A->val == B->val && match_one(A, B))
            return true;

        if (isSubStructure(A->left, B))
            return true;
        if (isSubStructure(A->right, B))
            return true;

        return false;
    }
};