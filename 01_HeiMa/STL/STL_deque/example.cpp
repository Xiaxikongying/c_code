#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

//评委打分
class person
{
public:
    string name;
    int score;

    person(string name, int score)
    {
        this->name = name;
        this->score = score;
    }
};

void setScore(vector<person> &v)
{
    for (vector<person>::iterator it = v.begin(); it != v.end(); it++)
    {
        deque<int> d;
        for (int i = 0; i < 10; i++)
        {
            int s = rand() % 41 + 60; // 60-100分
            d.push_back(s);
        }
        sort(d.begin(), d.end());
        d.pop_back();
        d.pop_front();
        int sum = 0;
        for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
        {
            sum += (*dit);
        }
        int avg = sum / d.size();
        (*it).score = avg;
    }
}

int main()
{
    srand((unsigned int)time(NULL));
    //创建5名选手
    vector<person> v;
    string nameSeed = "ABCDE";
    for (int i = 0; i < 5; i++)
    {
        string name = "选手";
        name += nameSeed[i];

        int score = 0;
        person p(name, score);
        v.push_back(p);
    }
    setScore(v);

    //打分

    for (vector<person>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << (*it).name << " " << (*it).score << endl;
    }

    system("pause");
    return 0;
}