#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int myop1(int x, int y)
{
   return x - y;
}

class myop2
{
   .
public:
   int operator()(int x, int y)
   {
      return x * y;
   }
};

int main()
{
   int arr[]{10, 20, 30};
   cout << accumulate(arr, arr + 3, 100) << endl;
   cout << accumulate(arr, arr + 3, 100, myop1) << endl;
   cout << accumulate(arr, arr + 3, 100, myop2()) << endl;
   system("pause");
   return 0;
}
