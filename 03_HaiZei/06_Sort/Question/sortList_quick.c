/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/*
leetcode 148 链表排序
给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
输入：head = [4,2,1,3]
输出：[1,2,3,4]
*/

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        int l = head->val;
        int r = head->val;
        ListNode *p = head;
        ListNode *h1 = nullptr, *h2 = nullptr, *q;
        while (p)
        {
            l = min(p->val, l);
            r = max(p->val, r);
            p = p->next;
        }
        if (l == r)
            return head; // 说明链表中的值都相同

        int z = (l + r) / 2;
        p = head;

        while (p)
        {
            q = p->next;
            if (p->val <= z)
            {
                p->next = h1;
                h1 = p;
                //向h1的头部插入 p
            }
            else
            {
                p->next = h2;
                h2 = p;
                //向h2的头部插入 p
            }
            p = q;
        }
        h1 = sortList(h1);
        h2 = sortList(h2);
        p = h1;
        while (p->next)
            p = p->next;
        p->next = h2;
        return h1;
    }
};