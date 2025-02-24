class Solution
{
public:
   int minimumBuckets(string hamsters)
   {
      int n = hamsters.size();
      int res = 0;
      for (int i = 0; i < n; ++i)
      {
         if (hamsters[i] == 'H')
         {
            // 如果右边为 .  则直接向后跳跃两格
            if (i + 1 < n && hamsters[i + 1] == '.')
            {
               ++res;
               i += 2;
            }
            else if (i - 1 >= 0 && hamsters[i - 1] == '.')
               ++res;
            else
               return -1;
         }
      }
      return res;
   }
};