#include <iostream>
#include <vector>
#include <deque>
#include <climits>
using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<pair<int, int>>> adj; // Adjacency list with weights

public:
    Graph(int vertices) : V(vertices), adj(vertices) {}

    // Add an edge to the graph (directed with weights 0 or 1)
    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
        // For undirected graphs, uncomment the next line
        // adj[v].push_back({u, weight});
    }

    // Shortest path using 0-1 BFS
    void shortestPath01BFS(int src) {
        vector<int> dist(V, INT_MAX); // Distance array initialized to infinity
        deque<int> dq;

        // Start 0-1 BFS from the source
        dist[src] = 0;
        dq.push_back(src);

        while (!dq.empty()) {
            int u = dq.front();
            dq.pop_front();

            for (auto &[v, weight] : adj[u]) {
                // If a shorter path to v is found
                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    // Push to the deque based on edge weight
                    if (weight == 0) {
                        dq.push_front(v);
                    } else {
                        dq.push_back(v);
                    }
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
    g.addEdge(0, 1, 0);
    g.addEdge(0, 3, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(3, 4, 0);
    g.addEdge(4, 5, 1);
    g.addEdge(2, 5, 0);

    cout << "Shortest paths using 0-1 BFS:\n";
    g.shortestPath01BFS(0);

    return 0;
}
