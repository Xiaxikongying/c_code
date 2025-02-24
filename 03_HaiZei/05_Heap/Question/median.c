// leetcode 295
/*
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // 返回 1.5 ((1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0

*/

class MedianFinder
{
public:
    typedef pair<int, int> PII;
    int tot;
    set<PII> s1, s2; // s1为大顶堆 存放较小的数   但是set是小顶堆 所以取反存入
                     // s2为小顶堆  存放较大的数
                     //若总数为奇数 多的数放s1
    MedianFinder()
    {
        tot = 0;
    }

    void addNum(int num)
    {
        if (s1.size() == 0 || num < -s1.begin()->first)
        {
            s1.insert(PII(-num, tot++));
        }
        else
        {
            s2.insert(PII(num, tot++));
        }
        if (s1.size() == s2.size() || s1.size() == s2.size() + 1)
            return;

        if (s1.size() < s2.size())
        {
            // s1中元素太少
            s1.insert(PII(-s2.begin()->first, tot++));
            s2.erase(s2.begin());
        }
        if (s1.size() > s2.size() + 1)
        {
            // s1中元素太多
            s2.insert(PII(-s1.begin()->first, tot++));
            s1.erase(s1.begin());
        }
        return;
    }

    double findMedian()
    {
        if ((s1.size() + s2.size()) % 2 == 1)
            return -s1.begin()->first;
        double a = -s1.begin()->first;
        double b = s2.begin()->first;
        return (a + b) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */