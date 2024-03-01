#include <bits/stdc++.h>
using namespace std;
const int INF = 1e2;

int minCoins(vector<int> &coins, int n, int value)
{
   int dp[n + 1][value + 1];

   for (int i = 0; i <= n; i++)
   {
      for (int v = 0; v <= value; v++)
      {
         if (v == 0)
            dp[i][v] = 0;
         else if (i == 0)
            dp[i][v] = INF;
         else if (coins[i - 1] <= v)
            dp[i][v] = min(dp[i - 1][v], 1 + dp[i][v - coins[i - 1]]);
         else
            dp[i][v] = dp[i - 1][v];

         if (i != 0)
            cout << setw(3) << dp[i][v] << " ";
      }
      cout << endl;
   }

   return dp[n][value];
}

int main()
{
   int n, value;
   cout << "Enter the number of coins: ";
   cin >> n;
   cout << "Enter the value to make: ";
   cin >> value;

   vector<int> coins(n);
   cout << "Enter the coins: ";
   for (int i = 0; i < n; i++)
      cin >> coins[i];

   int minCoinCount = minCoins(coins, n, value);
   cout << "\nMinimum coins required: " << minCoinCount << endl;

   return 0;
}
