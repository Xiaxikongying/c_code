/*给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，
评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。
注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

*/
//-- -- -- -- -- -- -- -- --leetcode 142 -- -- -- -- -- -- -- --

/*-----------解题思路------------
设置两个指针 v2 = 2*v1  速度不同
当v1到达环口是 设v1走过了路 长为a
则 v2在环中也走了 a
当 v2 与  v1 在环中 向遇时   （设环长X）
a + 2vt - vt =x
得vt = X-a
即 v2 在环中走了 x-a的长度  离环口还有 a 的距离

现在只需要 设置 一个指针从开头开始走
且两者速度相同，两者相遇是 位置一定是环口
*/
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return NULL;
        ListNode *p = head, *q = head;
        while (q && q->next) //如果有环 将一直跑下去
        {
            p = p->next;
            q = q->next->next;
            if (q == p)
            {
                q = head;
                while(q!=p)
                {
                    p = p->next;
                    q = q->next;
                }
                return q;
            }
        }
        return NULL;
    }
};
