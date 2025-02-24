#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>

using namespace std;

// BFS计算每个玩家的代数
void calGen(int root, unordered_map<int, vector<int>> &tree, unordered_map<int, int> &gen)
{
    queue<pair<int, int>> q; // (玩家id, 当前代数)
    q.push({root, 0});

    while (!q.empty())
    {
        int player = q.front().first;
        int dep = q.front().second;
        q.pop();

        gen[player] = dep;

        for (int child : tree[player])
        {
            q.push({child, dep + 1});
        }
    }
}

vector<int> findvio(int m, vector<int> &t_s, int n, vector<int> &bond_pairs)
{
    unordered_map<int, vector<int>> tree;
    unordered_map<int, int> gen;

    // 构建师徒关系树
    for (int i = 0; i < m; i += 2)
    {
        int tch = t_s[i];
        int stu = t_s[i + 1];
        tree[tch].push_back(stu);
    }

    // 假设0号玩家是树的根节点，计算每个玩家的代数
    calGen(0, tree, gen);

    set<int> vio;

    // 检查每对情缘关系是否违反师门规则
    for (int i = 0; i < n; i += 2)
    {
        int p1 = bond_pairs[i];
        int p2 = bond_pairs[i + 1];

        if (gen.count(p1) && gen.count(p2))
        {
            if (abs(gen[p1] - gen[p2]) < 3)
            {
                vio.insert(p1);
                vio.insert(p2);
            }
        }
    }

    // 将违反规则的玩家id按升序排序
    vector<int> res(vio.begin(), vio.end());
    sort(res.begin(), res.end());

    return res;
}

int main()
{
    int m, n;
    cin >> m;
    vector<int> t_s(m);
    for (int i = 0; i < m; ++i)
        cin >> t_s[i];
    
    cin >> n;
    vector<int> bond_pairs(n);
    for (int i = 0; i < n; ++i)
        cin >> bond_pairs[i];
    
    vector<int> vio = findvio(m, t_s, n, bond_pairs);

    for (int id : vio)
        cout << id << " ";
    cout << endl;
    system("pause");
    return 0;
}
