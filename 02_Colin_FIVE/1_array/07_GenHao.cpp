#include <iostream>
using namespace std;
double findsquareRoot(double x)
{
   double left = 0;
   double right = x;
   double mid = (left + right) / 2;
   double p = 0.00001;
   while (right - left > p)
   {
      if (mid * mid > x)
         right = mid;
      else
         left = mid;
      mid = (left + right) / 2;
   }
   return mid;
}


int main()
{
   cout << findsquareRoot(2) << endl;
   system("pause");
   return 0;
}
