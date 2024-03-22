#include <bits/stdc++.h>
using namespace std;

typedef struct
{
   string id;
   int profit, weight;
} Item;

void printItems(vector<Item> &items)
{
   cout << endl;
   for (auto item : items)
      cout << setw(3) << item.id << " ";
   cout << endl;

   for (auto item : items)
      cout << setw(3) << item.weight << " ";
   cout << endl;

   for (auto item : items)
      cout << setw(3) << item.profit << " ";
   cout << endl;
}

bool comparator(Item i1, Item i2)
{
   double r1 = (double)i1.profit / i1.weight;
   double r2 = (double)i2.profit / i2.weight;
   return r1 > r2;
}

double FractionalKnapsack(vector<Item> &items, int W)
{
   double totalProfit = 0;
   vector<string> pickedItems;

   for (Item item : items)
   {
      pickedItems.push_back(item.id);
      if (W > item.weight)
      {
         totalProfit += item.profit;
         W -= item.weight;
      }
      else
      {
         totalProfit += item.profit * (double)W / item.weight;
         break;
      }
   }

   cout << "\nPicked items: ";
   for (auto x : pickedItems)
      cout << x << " ";
   cout << endl;

   return totalProfit;
}

int main()
{
   int n, i, W;
   cout << "Enter the number of items & capity: ";
   cin >> n >> W;
   vector<Item> items(n);

   for (i = 0; i < n; i++)
   {
      cout << "Enter profit & weight for item-" << (i + 1) << ": ";
      items[i].id = "I" + to_string(i + 1);
      cin >> items[i].profit >> items[i].weight;
   }

   printItems(items);
   sort(items.begin(), items.end(), comparator);
   printItems(items);

   double profit = FractionalKnapsack(items, W);
   cout << "Total profit: " << profit << endl;

   return 0;
}