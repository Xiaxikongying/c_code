/*
对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果这个过程 结果为 1，那么这个数就是快乐数。
如果 n 是 快乐数 就返回 true ；不是，则返回 false 。

输入：n = 19
输出：true
解释：
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1

true
*/
//--------------------------解题思路
/*
上述数字 19--82--68--100--1
将 1 视为NULL 这些数视为链表
若链表没有环 则一定会到达1
若有环 则遍历过程一定会 遍历到两个相等的数字
*/

class Solution
{
public:
    int getNext(int x)
    {
        int y=0, a = 0;
        while (x)
        {
            a = x % 10;
            y += a * a;
            x /= 10;
        }
        return y;
    }
    bool isHappy(int n)
    {
        int p = n, q = n;
        while (q != 1)
        {
            p = getNext(p);
            q = getNext(getNext(q));
            if (p == q && q != 1)
                return false;
        }
        return true;
    }
};