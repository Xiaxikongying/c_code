#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
在一个问题测试中，有x = y的相等条件  也有x!=y的不等条件
我们只能让各个相等的数字之间连通，而不等条件没有连通性
所以，对于输入的n个条件，需要先拿出 相等的条件---->用于将节点连通
在遍历各个不等条件放入并查集中，判断是否合理

这就要求我们不能一次输入就进行一次操作，而是要将所以的输入的都保存起来.
若想要保存每一次输入的三个数字，则需要设计一个结构体

由于 data.a  data.b的范围很大，我们无法创建一个巨大的数组来存储关系，
只能用map表示
*/
struct Data
{
    int a, b, c;
};

class UnionSet
{
public:
    vector<int> fa;
    UnionSet(int n) : fa(n + 1)
    {
        for (int i = 0; i <= n; i++)
            fa[i] = i;
    }

    int get(int x)
    {
        return fa[x] = (fa[x] == x ? x : get(fa[x]));
    }
    void merge(int a, int b)
    {
        fa[get(a)] = get(b);
    }
};

Data data[1000000];

int main()
{
    int s, n;
    cin >> s;
    while (s--)
    {
        cin >> n;
        UnionSet U(n * 2);
        unordered_map<int, int> h;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> data[i].a >> data[i].b >> data[i].c;
            if (h.find(data[i].a) == h.end())
                h[data[i].a] = cnt++;
            if (h.find(data[i].b) == h.end())
                h[data[i].b] = cnt++;
        }

        //先遍历相等的条件，建立连通图
        for (int i = 0; i < n; i++)
        {
            if (data[i].c == 0)
                continue;
            U.merge(h[data[i].a], h[data[i].b]);
        }

        int falg = 1;
        for (int i = 0; i < n; i++)
        {
            if (data[i].c == 1)
                continue;
            if (U.get(h[data[i].a]) == U.get(h[data[i].b]))
            {
                falg = 0;
                break;
            }
        }
        if (falg)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    system("pause");
    return 0;
}
