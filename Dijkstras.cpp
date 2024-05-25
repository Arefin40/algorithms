#include <bits/stdc++.h>
using namespace std;

int nodes, edges;
vector<vector<int>> graph;
vector<int> dist;
vector<bool> visited;

void addEdge(int u, int v, int w)
{
    graph[u][v] = w;
    graph[v][u] = w;
}

void printMatrix()
{
    cout << "\nAdjacency matrix:" << endl;
    for (auto row : graph)
    {
        for (auto x : row)
            cout << x << " ";
        cout << endl;
    }
    cout << endl;
}

int getNearestUnvisitedNode()
{
    int min = INT_MAX, minIndex;

    for (int i = 0; i < nodes; i++)
    {
        if (!visited[i] && dist[i] <= min)
        {
            min = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void dijkstras(int source)
{
    dist[source] = 0;

    for (int i = 0; i < nodes - 1; i++)
    {
        int u = getNearestUnvisitedNode();

        visited[u] = true;

        for (int v = 0; v < nodes; v++)
        {
            if (!visited[v]                        // not visited
                && graph[u][v]                     // u and v connected
                && dist[u] != INT_MAX              //
                && dist[u] + graph[u][v] < dist[v] // lower cost than previous
            )
                dist[v] = dist[u] + graph[u][v];
        }
    }

    // print distance
    cout << "distance: ";
    for (auto d : dist)
        cout << d << " ";
    cout << endl;
}

int main()
{
    cin >> nodes >> edges;

    graph.resize(nodes, vector<int>(nodes, 0));
    dist.resize(nodes, INT_MAX);
    visited.resize(nodes, false);

    while (edges--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }

    printMatrix();

    int source;
    cout << "Enter source: ";
    cin >> source;

    dijkstras(source);

    return 0;
}

// Graph image: https://media.licdn.com/dms/image/D4E12AQH4qXCp_WrrbA/article-cover_image-shrink_720_1280/0/1687401734846?e=1721865600&v=beta&t=X7yVQxVlDMyrYr1pqQE11VoYOHKlrxRgQPzS60-KqU8