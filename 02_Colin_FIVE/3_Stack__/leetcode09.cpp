//剑指 Offer 09. 用两个栈实现队列
class CQueue
{
public:
    CQueue() {}
    stack<int> s1;
    stack<int> s2;
    void appendTail(int value)
    {
        int temp;
        while (!s2.empty())
        {
            temp = s2.top();
            s2.pop();
            s1.push(temp);
        }
        temp = value;
        s1.push(temp);
    }

    int deleteHead()
    {
        int temp;
        while (!s1.empty())
        {
            temp = s1.top();
            s1.pop();
            s2.push(temp);
        }

        if (s2.empty())
            return -1;
        temp = s2.top();
        s2.pop();
        return temp;
    }
};
