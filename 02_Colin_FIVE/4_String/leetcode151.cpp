class Solution
{
public:
    // 用于反转字符串中从索引 l 到索引 r 的字符
    void reverse(string &s, int l, int r)
    {
        for (int i = l, j = r - 1; i < j; i++, j--)
        {
            swap(s[i], s[j]); // 交换对称位置上的字符
        }
    }

    // 反转字符串中的单词顺序
    string reverseWords(string s)
    {
        int n = s.size();
        reverse(s, 0, n); // 首先整体反转整个字符串

        int p = 0;
        int q = 0;
        //删除头部和中间部分的空格
        while (p < n)
        {
            if (s[p] != ' ' || (p > 0 && s[p - 1] != ' ')) //当前不是空格，上一个也不是
            {
                s[q] = s[p]; // 将非空格字符复制到处理后的字符串中
                q++;
            }
            p++;
        }

        // 删除末尾的空格
        if (q > 0 && s[q - 1] == ' ')
            q--;
        s.erase(q);

        p = 0;
        q = 0;
        while (q < s.size())
        {
            while (q < s.size() && s[q] != ' ')
                q++; // 移动指针 q 直到找到单词末尾

            reverse(s, p, q); // 反转单词部分的字符
            q++;
            p = q;
        }
        return s;
    }
};