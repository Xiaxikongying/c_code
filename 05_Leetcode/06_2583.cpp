
class Solution
{
public:
    long long kthLargestLevelSum(TreeNode *root, int k)
    {
        int now = 1;  // 用于记录当前层的个数
        int next = 0; // 用于记录下一层的
        long long sum = 0;
        vector<long long> ans;
        TreeNode *node;
        queue<TreeNode *> q;

        if (root == nullptr)
            return 0;
        q.push(root);
        while (!q.empty())
        {
            node = q.front();
            q.pop();
            --now;
            sum += node->val;
            if (node->left != nullptr)
            {
                q.push(node->left);
                ++next;
            }
            if (node->right != nullptr)
            {
                q.push(node->right);
                ++next;
            }
            if (now == 0)
            {
                now = next;
                next = 0;
                ans.push_back(sum);
                sum = 0;
            }
        }
        sort(ans.begin(), ans.end(), greater<long long>());
        if (k > ans.size())
            return -1;
        return ans[k - 1];
    }
};