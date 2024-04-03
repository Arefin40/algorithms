#include <bits/stdc++.h>
#include "Graph.cpp"
using namespace std;

int nodes, edges;
Graph graph;
vector<bool> visited;

void DFS(int v)
{
   visited[v] = true;

   for (int neighbor : graph[v].neighbors)
   {
      if (!visited[neighbor])
         DFS(neighbor);
   }

   cout << v << " ";
}

int main()
{
   cin >> nodes >> edges;
   graph.resize(nodes);
   visited.resize(nodes);

   while (edges--)
   {
      string v1, v2;
      cin >> v1 >> v2;
      graph.addEdge(v1, v2);
   }

   int source;
   cout << "\nEnter source node: ";
   cin >> source;
   cout << "DFS: ";
   DFS(source);

   return 0;
}
