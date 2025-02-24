/*
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

//------------leedcode 206  反转链表------------------------------------
//普通方法
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode new_head;
        new_head.next = NULL;
        ListNode *p = head;
        ListNode *q;
        while(p)
        {
            q = p->next;
            p->next = new_head.next;
            new_head.next = p;
            p = q;
        }
        // 将 head 1 2 3 .。。。全都插入到 newhead后
        // new-0
        //new - 1 -0
        //new - 2 - 1 -0......
        return new_head.next;
    }
};


//递归
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode *tail = head->next;
        ListNode * new_head = reverseList(head->next);
        head->next = NULL;
        tail->next = head;
        return new_head;
    } 
    
};