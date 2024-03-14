#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high)
{
   int i = low, j = mid + 1, k = 0;
   int size = high - low + 1;
   int temp[size];

   while (i <= mid && j <= high)
      temp[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
   while (i <= mid)
      temp[k++] = arr[i++];
   while (j <= high)
      temp[k++] = arr[j++];

   for (i = 0; i < size; i++)
      arr[low + i] = temp[i];
}

void mergesort(vector<int> &arr, int low, int high)
{
   if (low < high)
   {
      int mid = low + (high - low) / 2;
      mergesort(arr, low, mid);
      mergesort(arr, mid + 1, high);
      merge(arr, low, mid, high);
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

   mergesort(arr, 0, n - 1);

   for (int x : arr)
      cout << x << " ";
   cout << endl;

   return 0;
}