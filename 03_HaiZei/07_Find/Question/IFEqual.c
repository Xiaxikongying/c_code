/*
给你一个整数数组 nums 。如果任一值在数组中出现 至少两次 ，返回 true ；如果数组中每个元素互不相同，返回 false 。
*/
bool containsDuplicate(vector<int> &nums)
{
    unordered_set<int> h;
    for (auto x : nums)
    {
        if (h.find(x) != h.end())
            return true;
        h.insert(x);
    }
    return false;
}
