/*

给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。
leetcode 160 交叉链表
*/

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int n1 = 0, n2 = 0;
        ListNode *h1 = headA;
        ListNode *h2 = headB;
        while (h1)
        {
            n1 += 1;
            h1 = h1->next;
        }
        while (h2)
        {
            n2 += 1;
            h2 = h2->next;
        }

        h1 = headA;
        h2 = headB;

        if (n1 > n2)
        {
            int t = n1 - n2;
            while (t--)
                h1 = h1->next;
            while (n2--)
            {
                if (h1->val == h2->val)
                    return h1;
                h1 = h1->next;
                h2 = h2->next;
            }
            return NULL;
        }

        if (n2 > n1)
        {
            int t = n2 - n1;
            while (t--)
                h2 = h2->next;
            while (n1--)
            {
                if (h1->val == h2->val)
                    return h1;
                h1 = h1->next;
                h2 = h2->next;
            }
            return NULL;
        }
    }
};