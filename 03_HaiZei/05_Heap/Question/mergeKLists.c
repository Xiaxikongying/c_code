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

// leetcode 23 合并k个升序链表
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        typedef pair<int, int> PII;
        set<PII> s;
        int n = lists.size();
        for (int i = 0; i < n; i++)
        {
            if (lists[i] == NULL)
                continue;
            s.insert(lists[i]->val, i);
            // first  存入的是数据
            // second 存入的是第几个链表
        }
        ListNode new_head; //虚拟头结点
        ListNode *q;
        ListNode *p = &new_head;
        new_head = NULL;
        while (s.size())
        {
            PII a = *s.begin();
            s.erase(s.begin());
            q = lists[a.second];                     // q 指向最小的链表
            lists[a.second] = lists[a.second]->next; //最小链表删除第一个元素
            p->next = q;                             //将最小的元素接在p后面
            q->next = NULL;                          //赋空
            p = q;                                   //指针移动

            if (lists[a.second])
            {
                s.insert(PII(list[a.second]->val, a.second));
                //再添加一个 删除链表 的元素
            }
        }
        return new_head.next;
    }
};