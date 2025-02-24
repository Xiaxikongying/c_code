#include <iostream>
#include <map>
using namespace std;

// map 和 multimap 的元素都是 pair
// pair 第一个元素 first 为 key 起到索引作用
//     第二个值为 second 为 value（真值）
// map 中的容器会按照 key 自动排序

// map 与 multimap 不可以有相同的 key 值

void printMap(map<int, string> &m)
{
    for (map<int, string>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key= " << (*it).first << "   value= " << (*it).second << endl;
    }
    cout << endl;
}

// 1.构造函数
void test01()
{
    map<int, string> m;
    m.insert(pair<int, string>(1, "a"));
    m.insert(pair<int, string>(5, "e"));
    m.insert(pair<int, string>(2, "b"));
    m.insert(pair<int, string>(4, "d"));
    m.insert(pair<int, string>(3, "c"));

    m.insert(make_pair(6, "f"));

    m[7] = "g";

    m.erase(3);

    printMap(m);
}

// 2.大小和交换
// empty()  size()  swap()

// 3.插入和删除
//插入有 insert() 和 m[key] = value
// clear() erase(begin,end) erase(pos)迭代器  erase(key)

// 4.查找和统计
// find(key) 返回一个迭代器     count(key)

void test02()
{
    map<int, string> m;
    m.insert(pair<int, string>(1, "a"));
    m.insert(pair<int, string>(5, "e"));
    m.insert(pair<int, string>(2, "b"));
    m.insert(pair<int, string>(4, "d"));
    m.insert(pair<int, string>(3, "c"));

    map<int, string>::iterator pos = m.find(4);
    if (pos != m.end())
    {
        cout << "key= " << pos->first << "   value= " << (*pos).second << endl;
    }
    else
    {
        cout << "未查找到该元素" << endl;
    }

    int c = m.count(3);
    cout << c << endl;
}

// 5.排序

class myCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
        //降序
    }
};

void test03()
{
    map<int, string,myCompare> m;
    m.insert(pair<int, string>(1, "a"));
    m.insert(pair<int, string>(5, "e"));
    m.insert(pair<int, string>(2, "b"));
    m.insert(pair<int, string>(4, "d"));
    m.insert(pair<int, string>(3, "c"));

    for (map<int, string, myCompare>::iterator it = m.begin(); it != m.end();it++)
    {
        cout<< "key= " << it->first << "   value= " << (*it).second << endl;
    }
}

int main()
{
    test02();
    system("pause");
    return 0;
}
