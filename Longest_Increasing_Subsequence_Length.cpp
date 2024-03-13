#include <bits/stdc++.h>
using namespace std;

int LISLength(vector<int> &arr)
{
   int i, index, n = arr.size();
   vector<int> temp;
   temp.push_back(arr[0]);

   for (i = 1; i < n; i++)
   {
      if (arr[i] > temp.back())
         temp.push_back(arr[i]);
      else
      {
         index = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
         temp[index] = arr[i];
      }
   }

   return temp.size();
}

int main()
{
   int i, n;
   cout << "Enter array size: ";
   cin >> n;
   vector<int> arr(n);

   cout << "Enter elements: ";
   for (i = 0; i < n; i++)
      cin >> arr[i];

   int lisSize = LISLength(arr);
   cout << "Longest Increasing Subsequence: " << lisSize << endl;

   return 0;
}