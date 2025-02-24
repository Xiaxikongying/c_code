/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
剑指 Offer 35. 复杂链表的复制
*/
class Solution
{
public:
    Node *getNewNode(int val)
    {
        Node *newnode = (Node *)malloc(sizeof(Node));
        newnode->val = val;
        newnode->next = newnode->random = NULL;
        return newnode;
    }

    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
            return head;

        //将拷贝节点放到原节点后面，例如1->2->3这样的链表就变成了这样1->1'->2->2'->3->3'
        Node *p = head;
        while (p)
        {
            Node *q = getNewNode(p->val);
            q->next = p->next;
            p->next = q;
            p = p->next->next;
        }

        //把拷贝节点的random指针安排上
        p = head;
        while (p)
        {
            if (p->random != NULL)
                p->next->random = p->random->next;
    
            p = p->next->next;
        }

        //分离拷贝节点和原节点，变成1->2->3和1'->2'->3'两个链表，后者就是答案
        p = head;
        Node *ret = head->next;
        Node *q = NULL;
        while (p->next)
        {
            q = p->next;
            p->next = q->next;
            p = q;
        }
        return ret;
    }
};