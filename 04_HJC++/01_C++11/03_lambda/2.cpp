#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print(int n) { cout << n << " "; }
int main()
{
    vector<int> vec = {1, 4, 5, 2, 3, 9, 0};
    for_each(vec.begin(), vec.end(), [](int n)
             { cout << n << " "; });
    cout << endl;

    sort(vec.begin(), vec.end(), [](int a, int b)
         { return a > b; });

    vec.erase(std::remove_if(vec.begin(), vec.end(), [](int n)
                             { return n % 2 == 0; }),
              vec.end());

    for_each(vec.begin(), vec.end(), print);
    cout << endl;
    system("pause");
    return 0;
}
