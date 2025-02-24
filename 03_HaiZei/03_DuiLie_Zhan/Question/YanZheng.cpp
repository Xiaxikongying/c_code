// leetcod   946
/*
给定 pushed 和 popped 两个序列，每个序列中的 值都不重复，只有当它们可能是在最初空栈上进行的推入 push 和弹出 pop 操作序列的结果时，返回 true；否则，返回 false 。

 

输入：pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
输出：false
解释：1 不能在 2 之前弹出。
*/

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        int x = 0;
        int n = pushed.size(); //入栈序列的下标
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            if (s.empty() || s.top() != popped[i])
            {
                while (x < pushed.size() && pushed[x] != popped[i])
                {
                    s.push(pushed[x]);
                    x++;
                }

                if (x == pushed.size()) //判断上面循环结束的原因
                    return false;

                s.push(pushed[x]); // 将与 pop.top相等的push[x]  推入栈中
                x++;
            }
            s.pop();
        }
        return true;
    }
};