#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

class Graph {
    int V; // Number of vertices
    vector<Edge> edges;

public:
    Graph(int vertices) : V(vertices) {}

    // Add an edge to the graph
    void addEdge(int u, int v, int weight) {
        edges.push_back({u, v, weight});
    }

    // DFS to check connectivity
    void dfs(int v, vector<bool> &visited, vector<vector<int>> &adj) {
        visited[v] = true;
        for (int u : adj[v]) {
            if (!visited[u]) {
                dfs(u, visited, adj);
            }
        }
    }

    // Check if the graph is connected
    bool isConnected() {
        vector<bool> visited(V, false);
        vector<vector<int>> adj(V);

        // Build adjacency list
        for (auto &e : edges) {
            adj[e.u].push_back(e.v);
            adj[e.v].push_back(e.u);
        }

        // Perform DFS from vertex 0
        dfs(0, visited, adj);

        // Check if all vertices are visited
        for (bool v : visited) {
            if (!v) return false;
        }
        return true;
    }

    // Reverse Delete Algorithm
    void reverseDeleteMST() {
        // Sort edges in descending order by weight
        sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
            return a.weight > b.weight;
        });

        int MSTWeight = 0;
        vector<Edge> MST;

        for (auto &edge : edges) {
            // Temporarily remove the edge
            Edge temp = edge;
            edges.erase(remove(edges.begin(), edges.end(), edge), edges.end());

            // Check if the graph is still connected
            if (!isConnected()) {
                // Add the edge back if the graph is disconnected
                edges.push_back(temp);
                MST.push_back(temp);
                MSTWeight += temp.weight;
            }
        }

        // Print the MST
        cout << "Edges in MST:\n";
        for (auto &e : MST) {
            cout << e.u << " - " << e.v << " (Weight: " << e.weight << ")\n";
        }
        cout << "Total weight of MST: " << MSTWeight << "\n";
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

    cout << "Reverse Delete MST:\n";
    g.reverseDeleteMST();

    return 0;
}
