#include <bits/stdc++.h>
using namespace std;

typedef struct Node
{
   int vertex, weight = 1;
   vector<int> neighbors;
   Node() {}
   Node(int v, int w = 1) : vertex(v), weight(w) {}
   void push_back(int v) { neighbors.push_back(v); }
} Node;

class Graph
{
private:
   int V;
   vector<Node> list;

   int toInt(const string &str)
   {
      if (isdigit(str[0]))
         return stoi(str);
      else if (isalpha(str[0]))
         return tolower(str[0]) - 'a';
      return 0;
   }

public:
   Graph() {}
   Graph(int vertices) : V(vertices) { list.resize(vertices); }

   int size() { return list.size(); }
   void resize(int size) { list.resize(size); }

   /**
    * @brief Adds an undirected edge between two vertices in the graph.
    *
    * @param v1 {string} The first vertex.
    * @param v2 {string} The second vertex.
    */
   void addEdge(string v1, string v2)
   {
      int u = toInt(v1), v = toInt(v2);
      list[u].vertex = u;
      list[v].vertex = v;
      list[u].push_back(v);
      list[v].push_back(u);
   }

   /**
    * @brief Accesses the list of neighbors of a vertex.
    *
    * @param vertex The vertex whose neighbors are to be accessed.
    * @return A reference to the list of neighbors of the given vertex.
    */
   Node &operator[](int vertex) { return list[vertex]; }

   /**
    * @brief Iterator for iterating over vertices
    */
   class iterator
   {
   private:
      vector<Node>::iterator it;

   public:
      iterator(vector<Node>::iterator _it) : it(_it) {}

      Node &operator*() const { return *it; }

      iterator &operator++()
      {
         ++it;
         return *this;
      }

      bool operator!=(const iterator &otherNode) const
      {
         return it != otherNode.it;
      }
   };

   iterator begin() { return iterator(list.begin()); }
   iterator end() { return iterator(list.end()); }
};

/**
 * @brief Overloaded << operator for printing vector
 */
ostream &operator<<(ostream &COUT, vector<int> &v)
{
   COUT << "[";
   for (size_t i = 0; i < v.size(); ++i)
   {
      if (i > 0)
         COUT << ",";
      COUT << v[i];
   }
   COUT << "]";
   return COUT;
}

/**
 * @brief Overloaded << operator for printing graph
 */
ostream &operator<<(ostream &COUT, Node &node)
{
   cout << node.vertex << ": " << node.neighbors;
   return COUT;
}

/**
 * @brief Overloaded << operator for printing graph
 */
ostream &operator<<(ostream &COUT, Graph &g)
{
   cout << "List Representation:" << endl;
   for (Node node : g)
      cout << node << endl;
   return COUT;
}
