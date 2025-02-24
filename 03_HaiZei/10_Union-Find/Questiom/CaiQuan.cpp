#include <iostream>
#include <vector>
using namespace std;
class UnionSet
{
public:
    vector<int> fa;
    vector<int> val; // val[i]--->表示点i到其父亲的权值
    /*
    由于猜拳只有三种结果---->输赢平，所以用权值表示与父亲的结果也应该只有三种
    所以权值只有  0(平)  1(输)  2(胜)
    若val>=3  ||  val<0 则需要取余 (在计算机中有两种取余的方法，一种是不会让余数小于0的，但这里不行，所以对于负数取余要先+3)  -2%3 = -2（1）
    */
    UnionSet(int n) : fa(n + 1), val(n + 1)
    {
        for (int i = 0; i <= n; i++)
        {
            fa[i] = i;
            val[i] = 0;
        }
    }
    int find(int x) //将找到的点挂在根节点上，并且改变其val
    {
        if (fa[x] == x)
            return x;
        int root = find(fa[x]); //先记录根节点。由于递归，执行下一句时，父亲已经挂在根节点上了
        val[x] = (val[x] + val[fa[x]] + 3) % 3;
        //在改变自己的父亲前，先将自己的父亲挂在根节点上
        //此时它的val已经改变，所以在将自己挂在根节点前，可以利用val[fa[x]]来计算自己的val[x]
        return fa[x] = root; //将自己挂在根上
    }

    void merge(int a, int b, int t) // t是ab之间的关系
    {
        int aa = find(a);
        int bb = find(b);
        if (aa == bb)
            return;
        //不仅不要合并节点，还需要合并val值
        fa[aa] = bb;
        val[aa] = (t + val[b] - val[a] + 3) % 3;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    UnionSet U(n);
    for (int i = 0; i < m; i++)
    {
        int op, a, b;
        cin >> op >> a >> b;
        if (op == 1) //提供信息
        {
            U.merge(a, b, 2);
        }
        else if (op == 2) //查询
        {
            if (U.find(a) == U.find(b))
            {
                int val = (U.val[a] - U.val[b] + 3) % 3; //由于前面使用的find(a),find(b),
                                                         //此时的ab都已经连接到了root上，它们val也改变了，使用va-vb就是它们之间的联系
                switch (val)
                {
                case 0:
                    cout << "Tie" << endl;
                    break;
                case 1:
                    cout << "Loss" << endl;
                    break;
                case 2:
                    cout << "Win" << endl;
                    break;
                }
            }
            else
                cout << "Unknown" << endl;
        }
    }

    system("pause");
    return 0;
}
