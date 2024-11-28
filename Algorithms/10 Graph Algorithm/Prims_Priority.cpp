#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

// Function to add edges to the graph
void addEdge(vector<vector<pii>>& graph, int u, int v, int weight) {
    graph[u].push_back({weight, v});
    graph[v].push_back({weight, u}); // Undirected graph
}

// Prim's algorithm to find MST
void primMST(vector<vector<pii>>& graph, int V) {
    priority_queue<pii, vector<pii>, greater<pii>> pq; // Min-heap based on edge weight
    vector<bool> visited(V, false);                    // Track visited vertices
    vector<int> parent(V, -1);                         // Stores parent of each vertex
    vector<int> key(V, INT_MAX);                       // Key values to pick minimum edge

    int mstCost = 0;                                   // Cost of MST

    // Start from vertex 0
    pq.emplace(0, 0);
    key[0] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // Skip if already visited
        if (visited[u])
            continue;

        visited[u] = true;
        mstCost += key[u];

        // Print the edge included in the MST (skip the first node)
        if (parent[u] != -1) {
            cout << "Edge: " << parent[u] << " - " << u << " with weight: " << key[u] << endl;
        }

        // Explore adjacent vertices
        for (auto [adjWeight, v] : graph[u]) {
            if (!visited[v] && adjWeight < key[v]) {
                key[v] = adjWeight;
                pq.emplace(key[v], v);
                parent[v] = u; // Update parent
            }
        }
    }

    cout << "Total cost of MST: " << mstCost << endl;
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<pii>> g(V);

    // Add edges to the graph (u, v, weight)
    addEdge(g,0, 1, 10);
    addEdge(g,0, 2, 6);
    addEdge(g,0, 3, 5);
    addEdge(g,1, 3, 15);
    addEdge(g,2, 3, 4);

    // Run Prim's algorithm
    primMST(g, V);

    return 0;
}
