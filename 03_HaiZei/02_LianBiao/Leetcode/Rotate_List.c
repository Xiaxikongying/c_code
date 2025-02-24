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
给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
输入：head = [1,2,3,4,5], k = 2
输出：[4,5,1,2,3]
//旋转两次
*/
//---------------------leetcode 61---------
class Solution
{
public:
    int getLenght(ListNode *head)
    {
        int n = 0;
        while (head)
        {
            n++;
            head = head->next;
        }
        return n;
    }

    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL)
            return head;

        int n = getLenght(ListNode * head);
        k %= n;
        if (k == 0)
            return head;

        ListNode *p = head, *q = head;
        for (int i = 0; i <= k; i++)
            p = p->next;
        while (p)
        {
            // p领先 q k+1 个位子
            p = p->next;
            q = q->next
        }
        p = q->next;    // P 找到新链表的头节点
        q->next = NULL; //将原来的链表断开
        q = p;          // p 与 q 都是新链表的头节点
        while (p->next) //换为q也行
        {
            p = p->next;
        }
        p->next = head;
        return q;
    }
};

//-------------自己写的-------------------
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL)
            return head;

        int n = 0;
        ListNode *p = head, *q = head;
        while (p->next)
        {
            n++;
            p = p->next;
        }
        n++;

        k %= n;
        if (k == 0)
            return head;

        p->next = head;
        int a = 0;
        a = n - k - 1;
        while (a--)
        {
            q = q->next;
        }
        p = q->next;
        q->next = NULL;
        return p;
    }
};