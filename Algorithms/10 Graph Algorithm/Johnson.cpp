#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <climits>
using namespace std;

#define INF INT_MAX

class Graph {
    int V; // Number of vertices
    vector<tuple<int, int, int>> edges; // Edge list: (u, v, weight)
    vector<vector<pair<int, int>>> adj; // Adjacency list for Dijkstra's algorithm

public:
    Graph(int vertices) : V(vertices), adj(vertices) {}

    // Add an edge to the graph
    void addEdge(int u, int v, int weight) {
        edges.emplace_back(u, v, weight);
        adj[u].emplace_back(v, weight);
    }

    // Bellman-Ford algorithm to find shortest paths from source
    bool bellmanFord(int src, vector<int> &h) {
        h[src] = 0;

        for (int i = 0; i < V; ++i) {
            for (auto &[u, v, w] : edges) {
                if (h[u] != INF && h[u] + w < h[v]) {
                    h[v] = h[u] + w;
                }
            }
        }

        // Check for negative weight cycles
        for (auto &[u, v, w] : edges) {
            if (h[u] != INF && h[u] + w < h[v]) {
                return false; // Negative weight cycle found
            }
        }
        return true;
    }

    // Dijkstra's Algorithm for a single source
    void dijkstra(int src, vector<int> &dist) {
        dist[src] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, src);

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (auto &[v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }
    }

    // Johnson's Algorithm
    void johnson() {
        // Step 1: Add a new vertex and edges with weight 0
        int newVertex = V;
        for (int i = 0; i < V; ++i) {
            edges.emplace_back(newVertex, i, 0);
        }

        // Step 2: Run Bellman-Ford from the new vertex
        vector<int> h(V + 1, INF);
        if (!bellmanFord(newVertex, h)) {
            cout << "Graph contains a negative weight cycle.\n";
            return;
        }

        // Step 3: Reweight the edges
        for (auto &[u, v, w] : edges) {
            w += h[u] - h[v];
        }

        // Step 4: Remove the extra vertex
        edges.erase(edges.end() - V, edges.end());

        // Step 5: Run Dijkstra's Algorithm for each vertex
        cout << "All-Pairs Shortest Paths:\n";
        for (int u = 0; u < V; ++u) {
            vector<int> dist(V, INF);
            dijkstra(u, dist);

            // Adjust distances back to original weights
            for (int v = 0; v < V; ++v) {
                if (dist[v] != INF) {
                    dist[v] = dist[v] - h[u] + h[v];
                }
            }

            // Print shortest distances from vertex u
            cout << "From vertex " << u << ":\n";
            for (int v = 0; v < V; ++v) {
                if (dist[v] == INF) {
                    cout << "  To " << v << ": INF\n";
                } else {
                    cout << "  To " << v << ": " << dist[v] << '\n';
                }
            }
        }
    }
};

// Example usage
int main() {
    Graph g(5);
    g.addEdge(0, 1, -1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 2);
    g.addEdge(3, 2, 5);
    g.addEdge(3, 1, 1);
    g.addEdge(4, 3, -3);

    cout << "Johnson's Algorithm Output:\n";
    g.johnson();

    return 0;
}
