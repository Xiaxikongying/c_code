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
        ListNode *p = head, *q = head, *m = head;
        while (q && q->next) //如果有环 将一直跑下去
        {
            p = p->next;
            q = q->next->next;
            if (q == p) //p q相遇 表示有环存在
            {
                while (m != q)
                {
                    q = q->next;
                    m = m->next;
                }
                return q;
            }
        }
        return NULL;
    }
};
