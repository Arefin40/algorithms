#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int l, int r)
{
   int i = (l - 1), pivot = arr[r];

   for (int j = l; j < r; j++)
      if (arr[j] <= pivot)
         swap(arr[++i], arr[j]);

   swap(arr[++i], arr[r]);
   return i;
}

void quicksort(vector<int> &arr, int l, int r)
{
   if (l < r)
   {
      int p = partition(arr, l, r);
      quicksort(arr, l, p - 1);
      quicksort(arr, p + 1, r);
   }
}

int main()
{
   int n;
   cout << "Enter array size: ";
   cin >> n;

   vector<int> arr(n);
   cout << "Enter array elements: ";
   for (int i = 0; i < n; i++)
      cin >> arr[i];

   quicksort(arr, 0, n - 1);

   for (int x : arr)
      cout << x << " ";
   cout << endl;

   return 0;
}