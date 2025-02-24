//给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
//--------------leetcod 19

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int count = 0;
        ListNode *p = head, *q = head;
        while (p->next)
        {
            count++;
            p = p->next;
        }
        count++;

        if (count == 1) //若只有一个节点 直接返回空
            return NULL;

        if (n == count) //若删除的是头节点 则直接返回头节点的下一个节点
            return q->next;

        int a = count - n - 1;
        while (a--)
            q = q->next;
        q->next = q->next->next;
        return head;
    }
};

//上述方法 需要分类讨论
//用虚拟头节点 可以统一操作
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode new_head, *p = &new_head;
        new_head.next = head;
        ListNode *q = p;
        for (int i = 0; i <= n;i++)
            q = q->next;
       while(q)
       {
           p = p->next;
           q = q->next;
       }
       p->next = p->next->next;
       return new_head.next;
    }
};