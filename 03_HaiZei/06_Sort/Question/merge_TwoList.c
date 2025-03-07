/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]
*/
// leetcode 21

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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode ret;
        ListNode *p = &ret;
        while (list1 || list2)
        {
            if (list2 == NULL || (list1 && list1->val < list2->val))
            {
                p->next = list1;
                list1 = list1->next;
                p = p->next;
            }
            else
            {
                p->next = list2;
                list2 = list2->next;
                p = p->next;
            }
        }
        return ret.next;
    }
};