#include <bits/stdc++.h>
using namespace std;
const int INF = 1e2;

int minCoins(vector<int> &coins, int n, int value)
{
   int i, v;
   int dp[n + 1][value + 1];

   for (i = 0; i <= n; i++)
   {
      for (v = 0; v <= value; v++)
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

   // Backtracking
   i = n, v = value;
   vector<int> usedCoins;
   while (i > 0 && v > 0)
   {
      if (dp[i][v] != dp[i - 1][v])
      {
         usedCoins.push_back(coins[i - 1]);
         v -= coins[i - 1];
      }
      --i;
   }

   reverse(usedCoins.begin(), usedCoins.end());
   for (int x : usedCoins)
      cout << x << " ";
   cout << endl;
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
