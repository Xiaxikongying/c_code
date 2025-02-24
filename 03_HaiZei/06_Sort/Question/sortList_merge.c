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

    ListNode *merge_sort(ListNode *head, int n)
    {
        if (n <= 1)
            return head;
            
        int l = n / 2;
        int r = n - l;
        ListNode *p = head, *p1, *p2, ret;
        for (int i = 1; i < l; i++)
            p = p->next;

        p1 = head;
        p2 = p->next;
        p->next = NULL;
        p1 = merge_sort(p1, l);
        p2 = merge_sort(p2, r);
        p = &ret;
        ret.next = NULL;

        while (p1 || p2)
        {
            if (p2 == NULL || (p1 && p1->val < p2->val))
            {
                //向 p 的尾部插入 p1
                p->next = p1;
                p = p1; // 或者换为p = p->next;
                p1 = p1->next;
            }
            else
            {
                p->next = p2;
                p = p2;
                p2 = p2->next;
            }
        }
        return ret.next;
    }

    ListNode *sortList(ListNode *head)
    {
        int n = getLenght(head);
        return merge_sort(head, n);
    }
};