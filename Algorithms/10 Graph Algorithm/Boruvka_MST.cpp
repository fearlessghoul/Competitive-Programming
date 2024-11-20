#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
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

    // Find the parent of a node (with path compression)
    int findParent(vector<int> &parent, int node) {
        if (parent[node] != node) {
            parent[node] = findParent(parent, parent[node]);
        }
        return parent[node];
    }

    // Union of two sets
    void unionSets(vector<int> &parent, vector<int> &rank, int u, int v) {
        int rootU = findParent(parent, u);
        int rootV = findParent(parent, v);

        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }

    // Boruvka's Algorithm
    void boruvkaMST() {
        vector<int> parent(V), rank(V, 0);
        for (int i = 0; i < V; ++i) parent[i] = i;

        int numComponents = V, MSTWeight = 0;

        while (numComponents > 1) {
            vector<int> cheapest(V, -1);

            // Find the cheapest edge for each component
            for (int i = 0; i < edges.size(); ++i) {
                int u = edges[i].u, v = edges[i].v, w = edges[i].weight;
                int setU = findParent(parent, u);
                int setV = findParent(parent, v);

                if (setU != setV) {
                    if (cheapest[setU] == -1 || edges[cheapest[setU]].weight > w) {
                        cheapest[setU] = i;
                    }
                    if (cheapest[setV] == -1 || edges[cheapest[setV]].weight > w) {
                        cheapest[setV] = i;
                    }
                }
            }

            // Add the cheapest edges to the MST
            for (int i = 0; i < V; ++i) {
                if (cheapest[i] != -1) {
                    int u = edges[cheapest[i]].u;
                    int v = edges[cheapest[i]].v;
                    int w = edges[cheapest[i]].weight;

                    int setU = findParent(parent, u);
                    int setV = findParent(parent, v);

                    if (setU != setV) {
                        MSTWeight += w;
                        unionSets(parent, rank, setU, setV);
                        cout << "Edge added: " << u << " - " << v << " (Weight: " << w << ")\n";
                        numComponents--;
                    }
                }
            }
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

    cout << "Boruvka's MST:\n";
    g.boruvkaMST();

    return 0;
}
