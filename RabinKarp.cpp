#include <bits/stdc++.h>
using namespace std;

void Rabinkarp(string pat, string txt)
{
   const int d = 26, prime = 101;
   int M = pat.size(), N = txt.size();
   int i, j, h = 1;

   // The value of h would be "pow(d, M-1)%prime"
   for (i = 0; i < M - 1; i++)
      h = (h * d) % prime;

   // Calculate the hash value of pattern and first window of text
   int hashPat = 0, hashText = 0;
   for (i = 0; i < M; i++)
   {
      hashPat = (d * hashPat + pat[i]) % prime;
      hashText = (d * hashText + txt[i]) % prime;
   }

   // Slide the pattern over text one by one
   for (i = 0; i <= N - M; i++)
   {
      if (hashPat == hashText && txt.substr(i, M) == pat)
         cout << "Pattern found at index " << i << endl;

      // Calculate hash value for next window of text
      if (i < N - M)
      {
         hashText = (d * (hashText - txt[i] * h) + txt[i + M]) % prime;
         if (hashText < 0)
            hashText += prime;
      }
   }
}

int main()
{
   string txt = "HELLO WORLD";
   string pat = "WORLD";
   Rabinkarp(pat, txt);
   return 0;
}
