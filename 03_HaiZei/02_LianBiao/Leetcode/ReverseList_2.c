//给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。
//请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
/*
输入：head = [1,2,3,4,5], left = 2, right = 4
输出：[1,4,3,2,5]
*/
//-----------------------------leetcode 92---------------

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
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
            return head;
        ListNode *tou = head, *end = head;
        for (int i = 1; i < right; i++)
        {
            if (i < left - 1)
            {
                tou = tou->next;
            }
            end = end->next;
        }
        ListNode *tail = end->next;
        end->next = NULL;
        ListNode *begin = tou->next;
        tou->next = NULL;

        ListNode new_head;
        new_head.next = NULL;
        ListNode *q;
        ListNode *p = begin;
        while (p)
        {
            q = p->next;
            p->next = new_head.next;
            new_head.next = p;
            p = q;
        }
        tou->next = end;
        begin->next = tail;
        return tou;
    }
};



class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
            return head;
        if (left != 1)
        {
            head->next = reverseBetween(head->next, left - 1, right - 1);
        }
        else
        {
            ListNode *tail = head->next, *new_head;
            new_head = reverseBetween(head->next, left, right-1);
            head->next = tail -> next;
            tail->next = head;
            head =  new_head;
        }
        return head;
    }
};
//编写递归函数时，不要太在意 程序过程的编写
//先假设程序已经好使 根据结果来编写后续 