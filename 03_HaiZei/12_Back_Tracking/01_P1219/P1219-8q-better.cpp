#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define MASK(n) ((1 << (n + 1)) - 2)
map<int, int> ind;
vector<vector<int>> b;
int num = 0;

void dfs(int i, int t1, int t2, int t3, vector<int> &a, int n)
{
    if (i - 1 == n)
    {
        b.push_back(a);
        num++;
        return;
    }
    for (int t = t1; t != 0; t -= (-t & t))
    {
        int j = ind[-t & t];
        if ((t2 & (1 << (i + j - 1))) && (t3 & (1 << (i - j + n))))
        {
            a[i - 1] = j;
            dfs(i + 1, t1 ^ (1 << j), t2 ^ (1 << (i + j - 1)), t3 ^ (1 << (i - j + n)), a, n);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n, -1);
    for (int i = 0; i < 2 * n; i++)
        ind[1 << i] = i;

    int t1 = MASK(n);
    int t2 = MASK(2 * n - 1);
    int t3 = MASK(2 * n - 1);
    dfs(1, t1, t2, t3, a, n);

    cout << num << endl;

    for (int i = 0; i <3; i++)
    {
        for (int j = 0; j < n; j++)
            cout << b[i][j] << " ";
        cout << endl;
    }

    system("pause");
    return 0;
}