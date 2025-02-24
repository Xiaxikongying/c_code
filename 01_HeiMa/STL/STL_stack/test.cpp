#include <iostream>
#include <stack>
using namespace std;

// stack 栈 后进先出 类似于弹匣
//有 pop() push() top()  empty() size()
//栈不允许遍历行为

void test01()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    while (!s.empty())
    {
        cout << "栈顶元素为：" << s.top() << endl;
        s.pop();
    }
    cout << s.size() << endl;
}

int main()
{
    test01();
    system("pause");
    return 0;
}
