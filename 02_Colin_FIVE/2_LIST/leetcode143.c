/*
leetcod 143. 重排链表   即折叠链表，将链表对折形成一个新链表
*/

class Solution
{
public:
    ListNode *FanZhuan(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *newHead = head; //头
        ListNode *p = head->next; //拿
        ListNode *q = p->next;    // 断
        newHead->next = NULL;

        while (q)
        {
            p->next = newHead;
            newHead = p;
            p = q;
            q = q->next;
        }
        p->next = newHead;
        newHead = p;
        return newHead;
    }

    void printf_Node(ListNode *head)
    {
        if (head == NULL)
            return;
        while (head)
        {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
        return;
    }

    void reorderList(ListNode *head)
    {
        if (head == NULL)
            return;

        //找到中间值
        ListNode *p, *q = head;
        while (q->next && q->next->next)
        {
            p = p->next;
            q = q->next->next;
        }
        q = p->next;
        p->next = NULL;
        p = head;

        //合并链表
        if (q)
        {
            q = FanZhuan(q);
            ListNode *p1 = p, *q1 = q;
            ListNode *q2 = q->next;
            while (q1)
            {
                q1->next = p1->next;
                p1->next = q1;
                p1 = p1->next->next;
                q1 = q2;
                if (q2)
                    q2 = q2->next;
            }
        }

        printf_Node(p);
    }
};