class Solution
{
public:
    TreeNode *getNewTreeNode(ListNode *node)
    {
        TreeNode *Tnode = new TreeNode;
        Tnode->val = node->val;
        Tnode->left = Tnode->right = nullptr;
        return Tnode;
    }
    TreeNode *addNode(ListNode *node, int len)
    {
        if (len == 0)
            return nullptr;
        if (len == 1)
        {
            return getNewTreeNode(node);
        }

        ListNode *p = node;
        for (int i = 0; i < len / 2; ++i)
        {
            p = p->next;
        }

        TreeNode *head = getNewTreeNode(p);
        head->left = addNode(node, len / 2);
        head->right = addNode(p->next, len - len / 2 - 1);
        return head;
    }

    TreeNode *sortedListToBST(ListNode *head)
    {
        int len = 0;
        ListNode *p = head;
        while (p)
        {
            p = p->next;
            ++len;
        }
        TreeNode *h = addNode(head, len);
        return h;
    }
};