#include <iostream>
#include <vector>
#include <queue>
#include <climits> // For INT_MAX
using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<pair<int, int>>> adj; // Adjacency list: (neighbor, weight)

public:
    Graph(int vertices) : V(vertices), adj(vertices) {}

    // Add an edge to the graph
    void addEdge(int u, int v, int weight) {
        adj[u].emplace_back(v, weight);
        adj[v].emplace_back(u, weight); // For undirected graph
    }

    // Dijkstra's Algorithm
    void dijkstra(int src) {
        vector<int> dist(V, INT_MAX); // Initialize distances to infinity
        dist[src] = 0; // Distance to source is 0

        // Min-heap priority queue: (distance, vertex)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, src);

        while (!pq.empty()) {
            auto [currDist, u] = pq.top();
            pq.pop();

            // Iterate over neighbors of vertex u
            for (auto &[v, weight] : adj[u]) {
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight; // Update distance
                    pq.emplace(dist[v], v); // Push updated distance to queue
                }
            }
        }

        // Print shortest distances
        cout << "Vertex\tDistance from Source (" << src << ")\n";
        for (int i = 0; i < V; ++i) {
            cout << i << "\t" << dist[i] << '\n';
        }
    }
};

// Example usage
int main() {
    Graph g(5); // Create a graph with 5 vertices
    g.addEdge(0, 1, 2);
    g.addEdge(0, 4, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 4, 9);

    int source = 0;
    cout << "Dijkstra's Algorithm Output:\n";
    g.dijkstra(source);

    return 0;
}
