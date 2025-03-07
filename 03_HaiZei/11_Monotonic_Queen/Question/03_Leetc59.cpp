/*
剑指 Offer 59 - II. 队列的最大值---->LCR 184. 设计自助结算系统
请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
若队列为空，pop_front 和 max_value 需要返回 -1

*/
#include <queue>
#include <deque>

class MaxQueue
{
public:
    queue<int> q;
    deque<int> mq;
    MaxQueue(){}

    int max_value()
    {
        if (q.empty())
            return -1;
        return mq.front();
    }

    void push_back(int value)
    {
        q.push_back(value);
        while (!mq.empty() && mq.back() < vaule)
            mq.pop_back();
        mq.push_back(value);
    }

    int pop_front()
    {
        if (q.empty())
            return -1;
        int val = q.front();
        q.pop();
        if(mq.front()==val)
            mq.pop_front();
        return val;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */