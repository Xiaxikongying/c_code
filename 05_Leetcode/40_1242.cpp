#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <mutex>
#include <thread>
#include <condition_variable>
using namespace std;

class HtmlParser
{
    // Return a list of all urls from a webpage of given url.
    // This is a blocking call, that means it will do HTTP request and return when this request is finished.
    vector<string> getUrls(string url);
};

class Solution
{
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser)
    {
        queue<string> q{{startUrl}};
        unordered_set<string> ust{{startUrl}};
        string hostname = getHostName(startUrl);
        vector<thread> threads;
        const int nthreads = std::thread::hardware_concurrency();
        mutex mtx;
        condition_variable cv;

        auto t = [&]
        {
            while (true)
            {
                unique_lock<mutex> lock(mtx);
                // �ȴ�30ms����queueΪ�գ������
                cv.wait_for(lock, 30ms, [&]()
                            { return q.size(); });
                if (q.empty())
                    return;
                // ��ȡ����
                auto cur = q.front();
                q.pop();
                lock.unlock();
                vector<string> urls = htmlParser.getUrls(cur); // ʹ��getUrls ��ȡcurҳ���ϵ���������
                lock.lock();
                for (const string &url : urls) // ����urls�������ظ��ķ���set��
                {
                    if (ust.count(url))
                    {
                        continue;
                    }
                    if (url.find(hostname) != string::npos) // ֻ��ȡ hostname ��ͬ�� URL
                    {
                        ust.insert(url);
                        q.push(url); // �µ����ӷ���queue�У�������ȡ
                    }
                }
                lock.unlock();
                cv.notify_all(); // ���������߳�
            }
        };

        for (int i = 0; i < nthreads; i++)
        {
            threads.emplace_back(t);
        }

        for (auto &thread : threads)
        {
            thread.join();
        }
        return {ust.begin(), ust.end()};
    }

private:
    string getHostName(string &s)
    {
        int firstIdx = s.find_first_of('/');
        int thirdIdx = s.find_first_of('/', firstIdx + 2);
        return s.substr(firstIdx + 2, thirdIdx - firstIdx - 2);
    }
};
