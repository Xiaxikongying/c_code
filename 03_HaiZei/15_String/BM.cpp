#include <iostream>
using namespace std;

#define TEST(func, s, t)                                      \
    {                                                         \
        printf("%s(%s, %s) = %d\n", #func, s, t, func(s, t)); \
    }

int *getDelta1(const char *t)
{
    int *delta1 = (int *)malloc(sizeof(int) * 256);
    for (int i = 0; i < 256; i++)
        delta1[i] = -1;
    for (int i = 0; t[i]; i++)
        delta1[t[i]] = i;
    return delta1;
}

int *getSuffixes(const char *t)
{
    int tlen = strlen(t);
    int *suff = (int *)malloc(sizeof(int) * tlen);
    suff[tlen - 1] = tlen;
    for (int i = 0; i < tlen - 1; i++)
    {
        int j = 0;
        while (j <= i && t[tlen - j - 1] == t[i - j])
            ++j;
        suff[i] = j;
    }
    return suff;
}

int *getDelta2(const char *t)
{
    int *suff = getSuffixes(t);
    int tlen = strlen(t), lastInd = tlen - 1;
    int *delta2 = (int *)malloc(sizeof(int) * tlen);
    for (int i = 0; t[i]; i++)
        delta2[i] = tlen;
    for (int i = 0; i < tlen; i++)
    {
        if (suff[i] != i + 1)
            continue;
        for (int j = 0; j <= lastInd - suff[i]; j++)
            delta2[j] = lastInd - i;
    }
    for (int i = 0; i < lastInd; i++)
    {
        delta2[lastInd - suff[i]] = lastInd - i;
    }
    return delta2;
}

int BM(const char *s, const char *t)
{
    int *delta1 = getDelta1(t);
    int *delta2 = getDelta2(t);
    int slen = strlen(s), tlen = strlen(t);
    for (int j = 0; j + tlen <= slen;)
    {
        int i = tlen - 1;
        while (i >= 0 && t[i] == s[j + i])
            --i;
        if (i == -1)
            return j;
        // printf("i=%d, delta1[%c]=%d, delta2[%d]=%d\n", i, s[j + i], delta1[s[j + i]], i, delta2[i]);
        j += max(i - delta1[s[j + i]], delta2[i]);
    }
    return -1;
}

int main()
{
    char s[100], t[100];
    while (~scanf("%s%s", s, t))
    {
        TEST(brute_force, s, t);
        TEST(sunday, s, t);
        TEST(BM, s, t);
    }
    return 0;
}
