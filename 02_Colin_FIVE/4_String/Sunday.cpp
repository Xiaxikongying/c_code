#include <iostream>
#include <string.h>
using namespace std;

int Sunday(string s1, string s2)
{
    int n1 = s1.size();
    int n2 = s2.size();
    if (n1 == 0 || n2 == 0)
        return -1;

    //---------next数组 初始化-------------
    int next[256];
    memset(next, -1, sizeof(int) * 256);
    for (int i = 0; i < n2; i++)
        next[s2[i]] = i;

    //------------匹配过程--------------
    int i = 0, j = 0, k = 0;
    // i j 是用来匹配两字符串字符是否相同的
    // k是指向一个字符串开始匹配的位子的
    while (i <= n1 && j <= n2)
    {
        //相同，向后移动
        while (s1[i] == s2[j] && s1[i] != '\0')
        {
            i++;
            j++;
        }
        //判断是否有相应的字符串
        if (j == n2)
            return k;
        //不同  k值变化
        if (s1[i] != s2[j])
        {
            k = k + n2 - next[s1[k + n2]];
            i = k;
            j = 0;
            if ((k + n2) > n1)
                return -1;
        }
    }
    return -1;
}

int main()
{
    string s1 = "wonwandonewowandandwonwonderone";
    string s2 = "wondero"; // 22

    int a = Sunday(s1, s2);
    cout << a << endl;

    string s3 = "ABABDABACDABABCABAB";
    string s4 = "ABABCABAB"; // 10
    int b = Sunday(s3, s4);
    cout << b << endl;

    string s5 = "babba";
    string s6 = "bbb"; 
    int c = Sunday(s5, s6);
    cout << c << endl;

    system("pause");
    return 0;
}
