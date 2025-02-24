class Solution
{
public:
    int length(TreeNode *node)
    {
        if (node == nullptr)
            return 0;
        int left = length(node->left);
        if (left == -1)
            return -1;
        int right = length(node->right);
        if (right == -1)
            return -1;

        if (abs(left - right) >= 2)
            return -1;
        else
            return max(left, right) + 1;
    }

    bool isBalanced(TreeNode *root)
    {
        if (length(root) == -1)
            return false;
        return true;
    }
};