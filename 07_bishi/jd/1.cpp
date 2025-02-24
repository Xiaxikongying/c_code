#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int c = b - a;
    int sum = (c + 1) * c / 2;
    cout << sum - b;
    return 0;
}
/*
题意
村子里有一些桩子，从左到右高度依次为1,1+2,1+2+3…，每两颗桩子之间的间隔为1.现在下了一场大雪，但是不知道雪下了多厚，现在给你两个数字，这是雪后某相邻两个桩子在雪面的高度，请你通过这两个数字计算雪的厚度。
输入描述
在一行中输入两个正整数a,b
1≤a<b≤5*10^5
输出描述
在一行中输出一个整数代表雪的厚度。我们可以证明，答案一定存在

示例1：
输入：
8 13
输出：
2

示例2：
输入：
10 15
输出：
0

*/