#include <iostream>
#include <vector>
#include <tuple>
#include <climits>
using namespace std;

class Graph {
    int V; // Number of vertices
    vector<tuple<int, int, int>> edges; // List of edges (u, v, weight)

public:
    Graph(int vertices) : V(vertices) {}

    // Add an edge to the graph
    void addEdge(int u, int v, int weight) {
        edges.emplace_back(u, v, weight);
    }

    // Bellman-Ford Algorithm
    void bellmanFord(int src) {
        vector<int> dist(V, INT_MAX); // Distance array
        dist[src] = 0; // Distance to source is 0

        // Relax all edges V-1 times
        for (int i = 0; i < V - 1; ++i) {
            for (auto &[u, v, weight] : edges) {
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }

        // Check for negative weight cycles
        for (auto &[u, v, weight] : edges) {
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                cout << "Graph contains a negative weight cycle.\n";
                return;
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
    Graph g(5); // Create a graph with 5 vertices
    g.addEdge(0, 1, -1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 2);
    g.addEdge(3, 2, 5);
    g.addEdge(3, 1, 1);
    g.addEdge(4, 3, -3);

    cout << "Bellman-Ford Algorithm Output:\n";
    g.bellmanFord(0);

    return 0;
}
