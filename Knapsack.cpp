#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> &weights, vector<int> &values, int n, int c)
{
   int i, w;
   int dp[n + 1][c + 1];
   cout << endl;

   for (i = 0; i <= n; i++)
   {
      for (w = 0; w <= c; w++)
      {
         if (i == 0 || w == 0)
            dp[i][w] = 0;
         else if (weights[i - 1] <= w)
            dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
         else
            dp[i][w] = dp[i - 1][w];

         cout << setw(2) << dp[i][w] << "  ";
      }
      cout << endl;
   }

   // Backtracking
   i = n, w = c;
   vector<int> pickedItems;

   while (i > 0 && w > 0)
   {
      if (dp[i][w] != dp[i - 1][w])
      {
         pickedItems.push_back(i);
         w -= weights[i - 1];
      }
      --i;
   }

   reverse(pickedItems.begin(), pickedItems.end());
   for (int x : pickedItems)
      cout << x << " ";
   cout << endl;
   return dp[n][c];
}

int main()
{
   int i, n, c;
   cout << "Enter the number of items: ";
   cin >> n;

   vector<int> weights(n), values(n);
   cout << "Enter weights of items: ";
   for (i = 0; i < n; i++)
      cin >> weights[i];

   cout << "Enter values of items: ";
   for (i = 0; i < n; i++)
      cin >> values[i];

   cout << "Enter the maximum capacity: ";
   cin >> c;

   int maxValue = knapsack(weights, values, n, c);
   cout << "\nMaximum value that can be picked is " << maxValue << endl;

   return 0;
}