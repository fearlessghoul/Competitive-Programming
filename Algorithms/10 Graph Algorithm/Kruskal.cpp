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

        function<bool(int,int)> unionSets = [&](int u, int v) {
            int rootU = find(u);
            int rootV = find(v);

            if (rootU == rootV) return false;
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
            return true;
        };

        int totalWeight = 0;
        vector<tuple<int, int, int>> mst; // (weight, u, v)

        for (auto &[weight, u, v] : edges) {
            if (unionSets(u, v)) {
                mst.emplace_back(weight, u, v);
                totalWeight += weight;
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

    cout << "\nUsing Kruskal's Algorithm:\n";
    g.kruskalMST();

    return 0;
}
