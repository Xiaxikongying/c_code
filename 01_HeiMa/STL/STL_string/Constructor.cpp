#include <iostream>
#include <string>
using namespace std;

//-------------------构造函数------------------------------
void test01()
{
    //构造函数
    //1.默认构造
    string s1;

    //2
    const char *str = "hello world";
    string s2(str);

    //3
    string s3(s2);

    //4
    string s4(10,'a');  //10个a

    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
}

int main()
{
    test01();
    system("pause");
}