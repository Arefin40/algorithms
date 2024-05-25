#include <bits/stdc++.h>
using namespace std;

bitset<30> col, d1, d2;
vector<vector<int>> board;

void printBoard()
{
   for (auto row : board)
   {
      for (auto col : row)
         cout << col << " ";
      cout << endl;
   }
   cout << endl;
}

void placeQueen(int r, int n)
{
   if (r == n)
   {
      printBoard();
      return;
   }

   for (int c = 0; c < n; c++)
   {
      if (!col[c] && !d1[r - c + n - 1] && !d2[r + c]) // is safe
      {
         board[r][c] = col[c] = d1[r - c + n - 1] = d2[r + c] = 1;
         placeQueen(r + 1, n);
         board[r][c] = col[c] = d1[r - c + n - 1] = d2[r + c] = 0;
      }
   }
}

int main()
{
   int n;
   cin >> n;
   board.resize(n, vector<int>(n, 0));
   placeQueen(0, n);

   return 0;
}