
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*
237. 删除链表中的节点
这道题细思极恐：如何让自己在世界上消失，但又不死? ——— 将自己完全变成另一个人，再杀了那个人就行了。
该方法也运用在BST的删除中
*/
class Solution
{
public:
     void deleteNode(ListNode *node)
     {
          node->val = node->next->val;
          if (node->next->next)
               node->next = node->next->next;
          else
               node->next = NULL;
     }
};