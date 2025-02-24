#include <iostream>

class ListNode
{
public:
    int val;        // 节点值
    ListNode *next; // 指向下一个节点的指针
    // 构造函数
    ListNode(int x) : val(x), next(nullptr) {}
    // 合并当前链表(this)与传入的另一个链表
    ListNode *mergeWith(ListNode *l2)
    {
        ListNode *l1 = this; // 当前链表 (this)

        // 创建一个哑节点（dummy node），它的 next 指向合并后的链表头
        ListNode *dummy = new ListNode(0);
        ListNode *current = dummy;
        // 遍历两个链表，依次比较它们的节点值
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val < l2->val)
            {
                current->next = l1;
                l1 = l1->next;
            }
            else
            {
                current->next = l2;
                l2 = l2->next;
            }
            current = current->next;
        }
        // 如果 l1 还没有遍历完，直接将剩余部分连接到 current
        if (l1 != nullptr)
            current->next = l1;
        // 如果 l2 还没有遍历完，直接将剩余部分连接到 current
        if (l2 != nullptr)
            current->next = l2;
        // 返回哑节点的下一个节点，即合并后的链表头
        this->next
    }
};
