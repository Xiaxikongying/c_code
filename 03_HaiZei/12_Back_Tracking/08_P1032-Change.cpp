#include <iostream>
#include <queue>
using namespace std;

#define MAX 20
string a, b;
string from[10], to[10];
int cnt = 0;
int ans = -1;

void bfs(string &a)
{
    queue<pair<string, int>> q;
    q.push(make_pair(a, 0));
    string now;
    int step = 0;
    while (!q.empty())
    {
        now = q.front().first;
        step = q.front().second;
        if (step > 10)
            return;
        q.pop();
        for (int i = 0; i < cnt; i++)
        {
            int pos = -1;
            pos = now.find(from[i]);
            while (pos != -1)
            {
                string change = now;
                change.erase(pos, from[i].size());
                change.insert(pos, to[i]);
                if (change == b)
                {
                    ans = step + 1;
                    return;
                }
                q.push(make_pair(change, step + 1));
                pos = now.find(from[i], pos + 1);
            }
        }
    }
}

int main()
{
    cin >> a >> b;
    while (cin >> from[cnt] >> to[cnt]) //输入ctrl + z  就可以结束输出
        cnt++;

    bfs(a);

    if (ans == -1)
        cout << "NO ANSWER!" << endl;
    else
        cout << ans << endl;

    system("pause");
    return 0;
}
