#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adjMatrix; // Adjacency matrix

public:
    Graph(int vertices) : V(vertices), adjMatrix(vertices, vector<int>(vertices, 0)) {}

    // Add an edge to the graph
    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight; // For undirected graph
    }

    // Find the vertex with the minimum distance
    int minDistance(vector<int> &dist, vector<bool> &visited) {
        int min = INT_MAX, minIndex = -1;

        for (int v = 0; v < V; ++v) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v];
                minIndex = v;
            }
        }
        return minIndex;
    }

    // Dijkstra's Algorithm
    void dijkstra(int src) {
        vector<int> dist(V, INT_MAX); // Distance from source to each vertex
        vector<bool> visited(V, false); // Visited vertices
        dist[src] = 0;

        for (int count = 1; count < V; ++count) {
            int u = minDistance(dist, visited); // Pick the minimum distance vertex
            visited[u] = true;

            for (int v = 0; v < V; ++v) {
                if (!visited[v] && adjMatrix[u][v] && dist[u] != INT_MAX && dist[u] + adjMatrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + adjMatrix[u][v];
                }
            }
        }

        // Print the result
        cout << "Vertex\tDistance from Source (" << src << ")\n";
        for (int i = 0; i < V; ++i) {
            cout << i << "\t" << dist[i] << '\n';
        }
    }
};

// Example usage
int main() {
    Graph g(5);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 4, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, 9);

    cout << "Dijkstra's Algorithm using Adjacency Matrix:\n";
    g.dijkstra(0);

    return 0;
}
