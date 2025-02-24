#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*

*/
struct Data
{
    int a, b;
    long c;
};

class UnionSet
{
public:
    vector<int> fa;
    vector<int> val; //取余2  val = 0--->在同一牢房中   1--->在不同牢房中
    UnionSet(int n) : fa(n + 1),val(n+1)
    {
        for (int i = 0; i <= n; i++)
        {
            fa[i] = i;
            val[i] = 0;
        }
    }

    int get(int x)
    {
        if (fa[x] == x)
            return x;
        int root = get(fa[x]);
        val[x] = (val[x] + val[fa[x]]) % 2;
        return fa[x] = root;
    }
    void merge(int a, int b, int t)
    {
        int aa = get(a);
        int bb = get(b);
        if (aa == bb)
            return;
        val[aa] = (val[b] + t - val[a]) % 2;
        fa[aa] = bb;
    }
};

bool cmp(Data &a, Data &b)
{
    return a.c > b.c;
}

Data data[100005];

int main()
{
    int n, m;

    cin >> n >> m; // n个犯人   m条记录
    UnionSet U(n + 2);
    for (int i = 0; i < m; i++)
        cin >> data[i].a >> data[i].b >> data[i].c;

    sort(data, data + m, cmp);
    int ans = 0;

    for (int i = 0; i < m; i++)
    {
        if (U.get(data[i].a) != U.get(data[i].b)) //两个罪犯不相连,将其分配在不同牢房中
            U.merge(data[i].a, data[i].b, 1);
        else //两个罪犯相连,可能在同一牢房
        {
            if ((U.val[data[i].a] + U.val[data[i].b]) % 2 == 0) //在同一牢房
            {
                ans = data[i].c;
                break;
            }
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}