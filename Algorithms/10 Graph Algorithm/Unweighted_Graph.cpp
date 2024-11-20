#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int vertices) : V(vertices), adj(vertices) {}

    // Add an edge to the graph (undirected or directed)
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Comment this line for directed graphs
    }

    // Shortest path using BFS
    void shortestPathBFS(int src) {
        vector<int> dist(V, INT_MAX); // Distance array initialized to infinity
        queue<int> q;

        // Start BFS from the source
        dist[src] = 0;
        q.push(src);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                // If a shorter path to v is found
                if (dist[v] > dist[u] + 1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        // Print the shortest distances
        cout << "Vertex\tDistance from Source (" << src << ")\n";
        for (int i = 0; i < V; ++i) {
            if (dist[i] == INT_MAX)
                cout << i << "\tINF\n";
            else
                cout << i << "\t" << dist[i] << "\n";
        }
    }
};

// Example usage
int main() {
    Graph g(6); // Graph with 6 vertices (0 to 5)
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(2, 5);

    cout << "Shortest paths using BFS:\n";
    g.shortestPathBFS(0);

    return 0;
}
