class Solution
{
public:
    bool findTargetIn2DPlants(vector<vector<int>> &plants, int target)
    {
        if (plants.size() == 0)
            return false;
        int i = 0;
        int j = plants[0].size() - 1;
        while (i < plants.size() && j >= 0)
        {
            if (plants[i][j] == target)
                return true;
            else if (plants[i][j] > target)
                j--;
            else if (plants[i][j] < target)
                i++;
        }
        return false;
    }
};
