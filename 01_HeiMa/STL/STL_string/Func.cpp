#include <iostream>
#include <string>
using namespace std;

void test01()
{
//---------赋值函数 assign-----
    string s1;
    string s2;
    string s3;
    string s4;
    s1.assign("hello world");
    s2.assign("hello world",5);
    s3.assign(s2);
    s4.assign(10,'a');
}

void test02()
{
    //拼接字符串
    string s1="hello";
    string s2;
    s2+= "world";
    string s3;
    s3.append("world");
}

void test03()
{
    //查找字符串
    string s1 = "helloworld";
    int p1 = s1.find("l");   //2
    cout << p1 << endl;
    int p2 = s1.rfind("l");
    cout << p2 << endl;    //8
}
void test04()
{
    //替换字符串
    string s1 = "abcdefg";
    s1.replace(1, 3, "00000"); //将1-3的字符替换为00000
    cout << s1 << endl;
}

void test05()
{
    //比较字符串
    string s1 = "abcdef";
    string s2 = "abcde";
    cout << s1.compare(s2) << endl;
}

void test06()
{
    //插入删除字符串
    string s1 = "abcdef";
    s1.insert(0, "0000");
    s1.erase(0, 2);
    cout << s1 << endl;
}

void test07()
{
    //字符串求字串
    string s1 = "abcdef";
    string s2=s1.substr(0,2);
    cout << s2 << endl;
}

int main()
{
    test07();
    system("pause");
}