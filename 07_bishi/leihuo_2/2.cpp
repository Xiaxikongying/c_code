#include <iostream>
#include <vector>
using namespace std;
class UnionSet
{
public:
    vector<int> fa;
    vector<string> vis;
    UnionSet(int n) : fa(n + 1, 0)
    {
        for (int i = 0; i <= n; ++i)
        {
            fa[i] = i;
            vis.emplace_back(n, '0');
        }
    }

    int find(int a)
    {
        return fa[a] = (fa[a] == a ? a : find(fa[a]));
    }

    void merge(int a, int b)
    {
        vis[a][b] = '1';
        vis[b][a] = '1';
        fa[find(a)] = find(b);
    }
};

int main()
{
    int n, m, t;
    cin >> n >> m >> t;
    UnionSet u(n);
    int a, b, c;
    for (int i = 0; i < m; ++i)
    {
        cin >> a >> b >> c;
        u.merge(a, b);
        u.merge(b, c);
        u.merge(a, c);
    }

    for (int i = 0; i < t; ++i)
    {
        cin >> a >> b;
        if (u.find(a) == u.find(b))
        {
            if (u.vis[a][b] == '1')
                cout << 1 << endl;
            else
                cout << 2 << endl;
        }
        else
        {
            cout << 3 << endl;
        }
    }

    system("pause");
    return 0;
}
