#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <numeric>
#include <functional>
using namespace std;

class Graph {
    int V; // Number of vertices
    vector<tuple<int, int, int>> edges; // Edges in the form (weight, u, v)

public:
    Graph(int vertices) : V(vertices) {}

    // Add an edge to the graph
    void addEdge(int u, int v, int weight) {
        edges.emplace_back(weight, u, v);
    }

    // Prim's Algorithm for MST
    void primMST() {
        vector<bool> visited(V, false);
        vector<vector<pair<int, int>>> adj(V); // Adjacency list for Prim's

        // Convert edge list to adjacency list
        for (auto &[weight, u, v] : edges) {
            adj[u].emplace_back(v, weight);
            adj[v].emplace_back(u, weight);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;
        minHeap.emplace(0, 0); // (weight, vertex)
        int totalWeight = 0;
        vector<pair<int, int>> mst; // (u, v)

        while (!minHeap.empty()) {
            auto [weight, u] = minHeap.top();
            minHeap.pop();

            if (visited[u]) continue;
            visited[u] = true;
            totalWeight += weight;

            // Add edges to the MST
            for (auto &[v, w] : adj[u]) {
                if (!visited[v]) {
                    minHeap.emplace(w, v);
                    mst.emplace_back(u, v);
                }
            }
        }

        cout << "Prim's MST Edges:\n";
        for (auto &[u, v] : mst) {
            cout << u << " - " << v << '\n';
        }
        cout << "Total Weight: " << totalWeight << '\n';
    }

    // Kruskal's Algorithm for MST
    void kruskalMST() {
        sort(edges.begin(), edges.end()); // Sort edges by weight
        vector<int> parent(V), rank(V, 0);
        for (int i = 0; i < V; i++) {
            parent[i] = i;  // Each node is its own parent initially
        }
        function<int(int)> find = [&](int u) {
            if (parent[u] != u) {
                parent[u] = find(parent[u]); // Path compression
            }
            return parent[u];
        };

        function<void(int,int)> unionSets = [&](int u, int v) {
            int rootU = find(u);
            int rootV = find(v);

            if (rootU != rootV) {
                if (rank[rootU] > rank[rootV]) {
                    parent[rootV] = rootU;
                } else if (rank[rootU] < rank[rootV]) {
                    parent[rootU] = rootV;
                } else {
                    parent[rootV] = rootU;
                    rank[rootU]++;
                }
            }
        };

        int totalWeight = 0;
        vector<tuple<int, int, int>> mst; // (weight, u, v)

        for (auto &[weight, u, v] : edges) {
            if (find(u) != find(v)) {
                mst.emplace_back(weight, u, v);
                totalWeight += weight;
                unionSets(u, v);
            }
        }

        cout << "Kruskal's MST Edges:\n";
        for (auto &[weight, u, v] : mst) {
            cout << u << " - " << v << " (Weight: " << weight << ")\n";
        }
        cout << "Total Weight: " << totalWeight << '\n';
    }
};

// Example usage
int main() {
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    cout << "Using Prim's Algorithm:\n";
    g.primMST();

    cout << "\nUsing Kruskal's Algorithm:\n";
    g.kruskalMST();

    return 0;
}
