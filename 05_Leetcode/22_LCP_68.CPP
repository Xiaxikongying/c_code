class Solution
{
public:
    int beautifulBouquet(vector<int> &flowers, int cnt)
    {
        int n = flowers.size();
        int ans = n;
        int left = 0, right = 0;
        // unordered_map<int, int> vis;
        vector<int> vis(100005, 0);
        while (right < n)
        {
            ++vis[flowers[right]];
            while (vis[flowers[right]] > cnt)
            {
                --vis[flowers[left]];
                ++left;
            }
            ans += right - left;
            ans %= 1000000007;
            ++right;
        }
        return ans;
    }
};