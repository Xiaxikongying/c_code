class Solution
{
private:
public:
    int calculate(string s)
    {
        vector<int> ans;
        char op = '+';
        int n = s.size();
        int num = 0;
        for (int i = 0; i < n; ++i)
        {
            if (isdigit(s[i])) // 如果是数字
                num = num * 10 + (s[i] - '0');
    
            if (!isdigit(s[i]) && s[i] != ' ' || i == s.size() - 1)
            {
                switch (op)
                {
                case '+':
                    ans.push_back(num);
                    break;
                case '-':
                    ans.push_back(-num);
                    break;
                case '*':
                    ans.back() *= num;
                    break;
                case '/':
                    ans.back() /= num;
                    break;
                }
                num = 0;
                op = s[i];
            }
        }
        int ret = 0;
        for (auto val : ans)
            ret += val;
        return ret;
    }
};