vector<vector<int>> findIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
{
    // write code here
    vector<vector<int>> res;
    int i = 0, j = 0, r, l;
    while (i < firstList.size() && j < secondList.size())
    {
        l = max(firstList[i][0], secondList[j][0]);
        r = min(firstList[i][1], secondList[j][1]);
        if (l <= r)                                                                                                                                                                                                                                                                                                                                                                                                                                                         
        {
            res.push_back({l, r});
        }
        if (firstList[i][1] < secondList[j][1])
            ++i;
        else
            ++j;
    }
    return res;
}