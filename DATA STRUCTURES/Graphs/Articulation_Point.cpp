#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<int> *adj;
    void APUtil(int u, vector<bool> &visited, vector<int> &disc,
                vector<int> &low, vector<int> &parent, vector<bool> &ap);

public:
    Graph(int V);
    void addEdge(int v, int w);
    void findAP();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new vector<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::APUtil(int u, vector<bool> &visited, vector<int> &disc,
                   vector<int> &low, vector<int> &parent, vector<bool> &ap) {
    static int time = 0;
    int children = 0;
    visited[u] = true;
    disc[u] = low[u] = ++time;

    for (int v : adj[u]) {
        if (!visited[v]) {
            children++;
            parent[v] = u;
            APUtil(v, visited, disc, low, parent, ap);
            low[u] = min(low[u], low[v]);

            if (parent[u] == -1 && children > 1)
                ap[u] = true;

            if (parent[u] != -1 && low[v] >= disc[u])
                ap[u] = true;
        } else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

void Graph::findAP() {
    vector<bool> visited(V, false);
    // disc[u]: Discovery time of vertex u
    // low[u]: Earliest visited vertex reachable from u
    // parent[u]: Parent vertex in DFS tree
    // ap[u]: Boolean array to store articulation points
    vector<int> disc(V, -1), low(V, -1), parent(V, -1);
    vector<bool> ap(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i])
            APUtil(i, visited, disc, low, parent, ap);
    }

    cout << "Articulation Points: ";
    for (int i = 0; i < V; i++) {
        if (ap[i])
            cout << i << " ";
    }
    cout << endl;
}

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.findAP();
    return 0;
}
// DFS Traversal: O(V + E)
// Each edge is visited once
// Overall Complexity: O(V + E)