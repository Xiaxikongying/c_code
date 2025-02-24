/*
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
输入: s = "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

//leetcode 3. 无重复字符的最长子串
*/

class Solution
{
public:
    bool check(string &s, int L)
    {
        int cnt[1000] = {0}; // L窗口内每种字符出现的次数
        int k = 0;           //不同字符的种类
        for (int i = 0; s[i]; i++)
        {
            cnt[s[i]]++; // s[i]字符出现 +1

            if (cnt[s[i]] == 1) //若 s[i]字符为第一次出现 就++
                k++;

            if (i >= L)
            {
                cnt[s[i - L]]--;
                if (cnt[s[i-L]] == 0)
                    k--;
            }

            if (L == k)
                return true;
        }
        return false;
    }

    int lengthOfLongestSubstring(string s)
    {
        int head = 0, tail = s.size(), mid;
        // 111111 0000
        while (head < tail)
        {
            mid = (head + tail + 1) / 2;
            if (check(s, mid) == 1) //没有重复的
                head = mid;
            else
                tail = mid - 1;
        }
        return head; // head 与 tail 重合
    }
};