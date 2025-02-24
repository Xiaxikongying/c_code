#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(10));
    vector<int> num(n, 0);
    vector<int> sum(n, 0);
    vector<int> cnt(10);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            cin >> arr[i][j];
            if (arr[i][j] > 0)
                ++num[i];
            if (arr[i][j] == 2)
            {
                ++cnt[j];
                ++sum[i];
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        if (num[i] < 3 || sum[i] > 5 || sum[i] > num[i] - 2)
        {
            for (int j = 0; j < 10; ++j)
            {
                if (arr[i][j] == 2)
                    --cnt[j];
            }
        }
    }

    vector<int> ind(10);
    for (int i = 0; i < 10; ++i)
        ind[i] = i;
    sort(ind.begin(), ind.end(), [&](int a, int b)
         { return cnt[a] > cnt[b]; });

    for (int i = 0; i < 10; ++i)
    {
        cout << ind[i] + 1 << " ";
        if (cnt[ind[i]] != cnt[ind[i + 1]])
            break;
    }
    cout << endl;

    system("pause");
    return 0;
}
