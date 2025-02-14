#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list
    vector<vector<int>> revAdj; // Reversed graph adjacency list

    void fillOrder(int v, vector<bool> &visited, stack<int> &Stack) {
        visited[v] = true;
        for (int i : adj[v]) {
            if (!visited[i])
                fillOrder(i, visited, Stack);
        }
        Stack.push(v);
    }

    void DFSUtil(int v, vector<bool> &visited, vector<int> &component) {
        visited[v] = true;
        component.push_back(v);
        for (int i : revAdj[v]) {
            if (!visited[i])
                DFSUtil(i, visited, component);
        }
    }

public:
    Graph(int V) : V(V), adj(V), revAdj(V) {}

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        revAdj[w].push_back(v); // Reverse edge for transpose graph
    }

    void findSCCs() {
        stack<int> Stack;
        vector<bool> visited(V, false);
        
        for (int i = 0; i < V; i++) {
            if (!visited[i])
                fillOrder(i, visited, Stack);
        }
        
        fill(visited.begin(), visited.end(), false);
        
        while (!Stack.empty()) {
            int v = Stack.top(); Stack.pop();
            if (!visited[v]) {
                vector<int> component;
                DFSUtil(v, visited, component);
                
                cout << "SCC: ";
                for (int node : component)
                    cout << node << " ";
                cout << endl;
            }
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    
    cout << "Strongly Connected Components are:\n";
    g.findSCCs();
    
    return 0;
}
