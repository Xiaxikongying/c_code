#include <iostream>
#include <vector>
using namespace std;

class UnionSet
{
public:
    vector<int> fa;  // 父节点
    vector<int> val; // 人数
    UnionSet(int n) : fa(n + 1), val(n + 1, 1)
    {
        for (int i = 0; i <= n; ++i)
        {
            fa[i] = i;
        }
    }

    int find(int x)
    {
        return fa[x] = (fa[x] == x ? x : find(fa[x]));
    }

    void merge(int a, int b)
    {
        int aa = find(a);
        int bb = find(b);
        if (aa == bb)
            return;
        if (val[aa] < val[bb])
        {
            fa[aa] = bb;
            val[bb] += val[aa];
        }
        else
        {
            fa[bb] = aa;
            val[aa] += val[bb];
        }
    }
};

int getdis(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    vector<int> y(n);
    for (int i = 0; i < n; ++i)
        cin >> x[i];
    for (int i = 0; i < n; ++i)
        cin >> y[i];

    UnionSet u(n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (getdis(x[i], y[i], x[j], y[j]) <= k && i != j)
            {
                u.merge(i, j);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        cout << u.fa[i] << "  " << u.val[i] << endl;
        ans = max(ans, u.val[i]);
    }
    cout << ans << endl;
    system("pause");
    return 0;
}
//