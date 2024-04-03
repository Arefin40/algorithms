#include <bits/stdc++.h>
#include "Graph.cpp"
using namespace std;

int nodes, edges;
Graph graph;

void BFS(int source)
{
   vector<bool> visited(graph.size(), false);
   queue<int> q;
   q.push(source);
   visited[source] = true;

   cout << "BFS: ";
   while (!q.empty())
   {
      int currentVertex = q.front();
      cout << currentVertex << " ";
      q.pop();

      for (int neighbor : graph[currentVertex].neighbors)
         if (!visited[neighbor])
         {
            q.push(neighbor);
            visited[neighbor] = true;
         }
   }
   cout << endl;
}

int main()
{

   cin >> nodes >> edges;
   graph.resize(nodes);

   while (edges--)
   {
      string v1, v2;
      cin >> v1 >> v2;
      graph.addEdge(v1, v2);
   }

   int source;
   cout << "\nEnter source node: ";
   cin >> source;
   BFS(source);

   return 0;
}