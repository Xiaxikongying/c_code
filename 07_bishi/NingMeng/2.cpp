#include <iostream>
#include <string>
#include <bitset>

using namespace std;

string getGrayCode(int n, int k)
{
    int gray = k ^ (k >> 1);              // 生成Gray码
    bitset<32> grayBits(gray);            // 将Gray码转换为二进制格式
    string result = grayBits.to_string(); // 转换为字符串形式
    return result.substr(32 - n);         // 截取最后n位
}

int main()
{
    int n, k;
    cin >> n >> k;
    string grayCode = getGrayCode(n, k);
    cout << grayCode << endl; // 输出Gray码
    system("pause");
    return 0;
}

/*
如图所示，分别为n=1,2,3位数Gray码。三位数的Gray码是通过把两位数的码镜像扩展后，在前面补0和1后获得。(可以把蓝横线看作水面，则下半部分的蓝字为上半部分黑字在水中的倒影)。绿色箭头头镜像过程中的对应关系，红色箭头为高位补0，蓝色箭头为高位补1.最右边的数字为每个Gray码对应的编号。
要求写程序，对任意给定的位数和序号输出它的Gray码。

输入描述
输入包含两个整数，第一个整数表示Gray码的位数，第二个数表示Gray码的序号
输出描述
输出对应数位和序号的Gray码。

测试数据1
输入：3 3
输出：010

测试数据2
输入：4 6
输出：0101
*/