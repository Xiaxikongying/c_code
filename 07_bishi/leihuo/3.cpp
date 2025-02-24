#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    int m, n, l;
    cin >> m >> n >> l;

    map<int, vector<int>> task_series;
    set<int> completed_tasks;

    // 输入任务系列
    for (int i = 0; i < m; ++i)
    {
        int series_id, num_tasks;
        cin >> series_id >> num_tasks;
        vector<int> tasks(num_tasks);
        for (int j = 0; j < num_tasks; ++j)
        {
            cin >> tasks[j];
        }
        task_series[series_id] = tasks;
    }

    // 输入玩家已经完成的任务
    for (int i = 0; i < n; ++i)
    {
        int task_id;
        cin >> task_id;
        completed_tasks.insert(task_id);
    }

    // 处理热更新指令
    for (int i = 0; i < l; ++i)
    {
        int command_type, series_id, task_id, new_task_id;
        cin >> command_type >> series_id >> task_id >> new_task_id;

        if (command_type == 0)
        { // 删除任务
            auto &tasks = task_series[series_id];
            tasks.erase(remove(tasks.begin(), tasks.end(), task_id), tasks.end());
        }
        else if (command_type == 1)
        { // 增加任务
            auto &tasks = task_series[series_id];
            auto it = find(tasks.begin(), tasks.end(), task_id);
            if (it != tasks.end())
            {
                tasks.insert(it + 1, new_task_id);
            }
            else
            {
                tasks.insert(tasks.begin(), new_task_id);
            }
        }
    }

    // 输出未完成的任务
    for (auto &series : task_series)
    {
        int series_id = series.first;
        vector<int> &tasks = series.second;

        // 找到第一个未完成的任务
        bool start_output = false;
        for (int task : tasks)
        {
            if (!completed_tasks.count(task))
            {
                if (start_output)
                {
                    cout << " ";
                }
                else
                {
                    start_output = true;
                }
                cout << task;
            }
        }
        if (start_output)
        {
            cout << endl;
        }
    }
    system("pause");
    return 0;
}
