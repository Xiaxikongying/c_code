#include <iostream>
#include <string.h>
using namespace std;

int KMP(string s1, string s2)
{
    int n1 = s1.size();
    int n2 = s2.size();

    int *next = (int *)malloc(sizeof(int) * n2);
    memset(next, 0, sizeof(int) * n2);
    for (int i = 1; i < n2; i++)
    {
        if (next[i - 1] == 0) //前一个next为0
        {
            if (s2[i] == s2[0])
                next[i] = 1;
        }
        else //前面一个next不为0
        {
            int a = next[i - 1];
            while (a != 0) //递归向下前一个next不为0时
            {
                if (s2[i] == s2[a]) //接上前一个next  所以i的next就等于前一个的+1
                {
                    next[i] = a + 1;
                    break;
                }
                a = next[a - 1]; //接不上的话，就再向下寻找
            }
            //若走到这里 a = 0  这里也就回到了第一种情况，即next[i-1] == 0
            if (a == 0 && s2[i] == s2[0]) //一直向下找，当前一个next为0时，就与s1[0] 匹配
                next[i] = 1;
        }
    }
    for (int i = 0; i < n2; i++)
        cout << next[i] << " ";
    cout << endl;
    //---------------------上面是得到next------下面是匹配-----------------------------------------------------
    int p = 0,
        q = 0;
    while (p < n1)
    {
        while (s1[p] == s2[q]) //匹配正确
        {
            if (q == n2 - 1)
                return p - q;
            p++;
            q++;
        }
        // s1[p] != s2[q] 匹配错误
        if (q >= 1) // q不为0   即找到了重复的部分
            q = next[q - 1];
        else //没有重复的部分，p++
            p++;
    }
    return -1;
}

int main()
{
    /*
    string s1 = "abcabceabcabcdabcabcabcdabcabcfabc";
    string s2 = "abcabcdabcabcf";
    // 17
    int a = KMP(s1, s2);
    cout << a << endl;


    string s1 = "wonwandonewowandandwonwonderone";
    string s2 = "wondero"; // 22

    int a = KMP(s1, s2);
    cout << a << endl;

    string s3 = "ABABDABACDABABCABAB";
    string s4 = "ABABCABAB"; // 10
    int b = KMP(s3, s4);
    cout << b << endl;

    string s5 = "AAAAAAB";
    string s6 = "AAB"; // 4
    int c = KMP(s5, s6);
    cout << c << endl;
*/
    string s7 = "aabaaabaaac";
    string s8 = "aabaaac"; // 4
    int d = KMP(s7, s8);
    cout << d << endl;
    system("pause");
    return 0;
}

/*
 int p = 0, q = 0;
    while (p < n1)
    {
        if (s1[p] == s2[q]) //匹配正确
        {
            if (q == n2 - 1)
                return p - q;
            p++;
            q++;
        }
        else //匹配错误
        {
            if (q >= 1) // q不为0
                q = next[q - 1];
            else
                p++;
        }
    }
    return -1;
*/