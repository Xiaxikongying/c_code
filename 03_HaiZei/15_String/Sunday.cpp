#include <iostream>
using namespace std;

int sunday(string a, string b)
{
   int n = a.size();
   int m = b.size();
   int len[256];
   for (int i = 0; i < 256; i++)
      len[i] = m + 1;
   for (int i = 0; b[i]; i++)
      len[b[i]] = m - i;

   for (int i = 0; i + m <= n; i += len[a[i + m]])
   {
      int flag = 1;
      for (int j = 0; j < m; j++)
      {
         if (a[i + j] == b[j])
            continue;
         flag = 0;
         break;
      }
      if (flag == 1)
         return i;
   }
   return -1;
}

int main()
{
   string a = "aecaeaecaed";
   string b = "aecaed";
   cout << sunday(a, b) << endl;
   system("pause");
   return 0;
}
