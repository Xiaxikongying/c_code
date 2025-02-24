int StringSplit(string str)
{
    // write code here
    int na = 0, nb = 0;
    int n = str.size();
    for (int i = 0; i < n; ++i)
    {
        if (str[i] == 'a')
            ++na;
    }
    nb = n - na;
    int cura = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (str[i] == 'a')
            ++cura;
        ans = max(ans, cura + nb - i - 1 + cura);
    }
}