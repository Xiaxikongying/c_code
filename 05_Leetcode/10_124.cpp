class Solution
{
    int max_sum = INT_MIN;

public:
    int maxPathSum(TreeNode *root)
    {
        getMax(root);
        return max_sum;
    }

    int getMax(TreeNode *node)
    {
        if (node == nullptr)
            return 0;
        int left_num = max(0, getMax(node->left));
        int right_num = max(0, getMax(node->right));

        int tmp_sum = left_num + right_num + node->val;
        max_sum = max(max_sum, tmp_sum);
        return node->val + max(left_num, right_num);
    }
};