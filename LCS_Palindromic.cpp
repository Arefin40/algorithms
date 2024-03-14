#include <bits/stdc++.h>
using namespace std;

void LCS(string &s1, string &s2)
{
   int n = s1.size(), m = s2.size();
   int dp[n + 1][m + 1];

   int i, j;
   cout << endl;
   for (i = 0; i <= n; i++)
   {
      for (j = 0; j <= m; j++)
      {
         if (i == 0 || j == 0)
            dp[i][j] = 0;
         else if (s1[i - 1] == s2[j - 1])
            dp[i][j] = 1 + dp[i - 1][j - 1];
         else
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

         cout << dp[i][j] << "  ";
      }
      cout << endl;
   }
   cout << endl;

   // Backtracking
   int lcs_size = dp[n][m];
   char lcs[lcs_size];
   i = n, j = m;

   while (i > 0 && j > 0)
   {
      if (s1[i - 1] == s2[j - 1])
      {
         lcs[--lcs_size] = s1[i - 1];
         --i;
         --j;
      }
      else if (dp[i - 1][j] > dp[i][j - 1])
         --i;
      else
         --j;
   }

   cout << "LCS: " << lcs << endl;
}

int main()
{
   string str, srev;
   cout << "Enter a string: ";
   cin >> str;

   srev = str;
   reverse(str.begin(), str.end());
   LCS(str, srev);

   return 0;
}