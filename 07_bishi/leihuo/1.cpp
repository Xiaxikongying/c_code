#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Event
{
    int t;   // 事件发生的时间，单位为分钟
    int num; // 参与人数，正数表示进入副本，负数表示离开副本

    // 自定义排序规则，时间小的排前面，如果时间相同，离开副本的事件排前面
    bool operator<(const Event &other) const
    {
        return t < other.t || (t == other.t && num < other.num);
    }
};

// 将时间转换为分钟
int TimeToMinutes(const string &tStr)
{
    int h = stoi(tStr.substr(0, 2));
    int m = stoi(tStr.substr(3, 2));
    return h * 60 + m;
}

int main()
{
    int M; // M组不同的服务器
    cin >> M;

    for (int i = 0; i < M; ++i)
    {
        int N; // 该服务器的帮会数
        cin >> N;

        vector<Event> events; // 用于存储事件

        for (int j = 0; j < N; ++j)
        {
            string tStr;
            int k, t;
            cin >> tStr >> k >> t;

            int startt = TimeToMinutes(tStr); // 副本开始时间
            int endt = startt + t;   // 副本结束时间

            // 记录副本开始和结束的事件
            events.push_back({startt, k});
            events.push_back({endt, -k});
        }

        // 按时间排序事件
        sort(events.begin(), events.end());

        int currentnum = 0; // 当前在副本中的人数
        int maxnum = 0;     // 同时在副本中的最大人数

        // 扫描所有事件，实时更新当前人数并记录最大值
        for (const auto &event : events)
        {
            currentnum += event.num;
            maxnum = max(maxnum, currentnum);
        }

        // 输出该服务器的最大人数
        cout << maxnum << endl;
    }
    system("pause");
    return 0;
}
