#include<bits/stdc++.h>
using namespace std;

class Graph {
    int V;  // Number of vertices
    vector<vector<int>> adj;  // Adjacency list
    bool directed;
public:
    // Constructor
    Graph(int V,bool direc=false) {
        this->V = V;
        adj.resize(V);
        directed=direc;
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        if(!directed) adj[v].push_back(u);  // For an undirected graph
    }

    // BFS for Disconnected Graph
    void BFS_Disconnected() {
        vector<bool> visited(V, false);  // Track visited nodes
        queue<int> q;

        for (int i = 0; i < V; i++) {  // Loop through all nodes
            if (!visited[i]) {  // Start BFS only for unvisited nodes
                q.push(i);
                visited[i] = true;

                cout << "BFS traversal for component starting at vertex " << i << ": ";
                while (!q.empty()) {
                    int u = q.front();
                    q.pop();
                    cout << u << " ";

                    // Visit all adjacent vertices of `u`
                    for (int v : adj[u]) {
                        if (!visited[v]) {
                            visited[v] = true;
                            q.push(v);
                        }
                    }
                }
                cout << endl;  // Separate components
            }
        }
    }

    // BFS traversal from a given source vertex
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS traversal starting from vertex " << start << ": ";
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        cout << endl;
    }

    // DFS helper function for recursive DFS traversal
    void DFSUtil(int v, vector<bool> &visited) {
        visited[v] = true;
        cout << v << " ";

        for (int u : adj[v]) {
            if (!visited[u]) {
                DFSUtil(u, visited);
            }
        }
    }

    // DFS traversal iterative
    void DFSUtil_Iterative(int start, vector<bool> &visited) {
        stack<int> s;  // Stack to simulate recursion
        s.push(start);
        while (!s.empty()) {
            int u = s.top();
            s.pop();

            // If the node is not visited, mark it and process it
            if (!visited[u]) {
                visited[u] = true;
                cout << u << " ";

                // Push all adjacent nodes to the stack
                // (reverse the adjacency list to maintain original DFS order)
                for (auto it = adj[u].rbegin(); it != adj[u].rend(); ++it) {
                    int v = *it;
                    if (!visited[v]) {
                        s.push(v);
                    }
                }
            }
        }
        cout << endl;
    }
    // DFS for Disconnected Graph
    void DFS_Disconnected() {
        vector<bool> visited(V, false);  // Track visited nodes

        // Perform DFS for each unvisited vertex
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {  // Start DFS only for unvisited nodes
                cout << "DFS traversal for component starting at vertex " << i << ": ";
                DFSUtil(i,visited);  // Call DFS from vertex `i`
                cout << endl;  // Separate components
            }
        }
    }

    // DFS traversal from a given source vertex
    void DFS(int start) {
        vector<bool> visited(V, false);
        cout << "DFS traversal starting from vertex " << start << ": ";
        DFSUtil(start, visited);
        cout << endl;
    }


    // Helper function for DFS-based topological sorting
    void topologicalSortUtil(int v, vector<bool> &visited, stack<int> &Stack) {
        // Mark the current node as visited
        visited[v] = true;

        // Recursively visit all the adjacent vertices
        for (int i : adj[v]) {
            if (!visited[i]) {
                topologicalSortUtil(i, visited, Stack);
            }
        }

        // Push the current vertex to the stack after visiting all adjacent nodes
        Stack.push(v);
    }

    // Function to perform topological sort
    void topologicalSort() {
        stack<int> Stack;              // Stack to store the topological order
        vector<bool> visited(V, false); // Mark all vertices as not visited

        // Call the helper function for each unvisited vertex
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                topologicalSortUtil(i, visited, Stack);
            }
        }

        // Print the contents of the stack in topological order
        while (!Stack.empty()) {
            cout << Stack.top() << " ";
            Stack.pop();
        }
        cout<<endl;
    }


    // Function to perform topological sort using Kahn's algorithm
    void topologicalSortusingKahn() {
        vector<int> in_degree(V, 0); // Initialize in-degree of all vertices as 0

        // Calculate in-degrees of all vertices
        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                in_degree[v]++;
            }
        }

        // Create a queue and enqueue all vertices with in-degree 0
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }

        // Initialize count of visited vertices and a vector for topological order
        vector<int> top_order;
        int count = 0;

        // Process the vertices in the queue
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            top_order.push_back(u);

            // Iterate through all neighbors of u and reduce their in-degree by 1
            for (int v : adj[u]) {
                if (--in_degree[v] == 0) {
                    q.push(v);
                }
            }

            count++;
        }

        // Check if there was a cycle
        if (count != V) {
            cout << "There exists a cycle in the graph, topological sorting is not possible.\n";
        } else {
            // Print topological order
            for (int i : top_order) {
                cout << i << " ";
            }
            cout << endl;
        }
    }

    // Helper function to perform all topological sorts
    void allTopologicalSortsUtil(vector<int>& result, vector<bool>& visited,vector<int>& in_degree) {
        bool allVisited = true; // Flag to check if all vertices are visited

        for (int i = 0; i < V; i++) {
            // If in-degree is 0 and not yet visited, we can add it to the order
            if (!visited[i] && in_degree[i] == 0) {
                // Mark as visited and add to current result
                visited[i] = true;
                result.push_back(i);

                // Reduce in-degree of all adjacent vertices
                for (int neighbor : adj[i]) {
                    in_degree[neighbor]--;
                }

                // Recur to construct the rest of the topological ordering
                allTopologicalSortsUtil(result, visited,in_degree);

                // Backtrack
                // Reset the in-degree of all adjacent vertices and visited status
                for (int neighbor : adj[i]) {
                    in_degree[neighbor]++;
                }
                result.pop_back();
                visited[i] = false;

                allVisited = false; // If any node was visited in this step
            }
        }

        // If all vertices are visited in this order, store this result
        if (allVisited) {
            for (int i : result) {
                cout << i << " ";
            }
            cout << endl;
        }
    }

    // Function to find all topological sorts
    void allTopologicalSorts() {
        vector<int> in_degree(V, 0); // Initialize in-degree of all vertices as 0

        // Calculate in-degrees of all vertices
        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                in_degree[v]++;
            }
        }
        vector<int> result;         // To store current topological order
        vector<bool> visited(V, false);  // To keep track of visited nodes
        allTopologicalSortsUtil(result, visited, in_degree);
    }

    // DFS utility to calculate departure times
    void dfs(int v, vector<bool>& visited, vector<int>& departure,int& time) {
        visited[v] = true;

        // Explore all adjacent vertices
        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, departure,time);
            }
        }
        // Assign departure time and increase the time counter
        departure[time++] = v;
    }

    // Function to perform topological sort using departure times
    void topologicalSortDeparture() {
        vector<bool> visited(V, false);
        vector<int> departure(V, -1);  // Stores each vertex in order of departure time
        int time=0;
        // Run DFS for each unvisited vertex
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, departure,time);
            }
        }
        reverse(departure.begin(),departure.end());
        // Print topological order
        cout << "Topological Sort: ";
        for (int &p : departure) {
            cout << p << " ";
        }
        cout << endl;
    }

    // Helper function for DFS-based cycle detection
    bool dfsCycleDetect(int v, vector<bool> &visited, vector<bool> &recStack) {
        // Mark the current node as visited and add it to the recursion stack
        visited[v] = true;
        recStack[v] = true;

        // Recur for all vertices adjacent to this vertex
        for (int neighbor : adj[v]) {

            // If the adjacent vertex is not visited, recursively call DFS
            // or
            // If the adjacent vertex is in the recursion stack, there is a cycle
            if (!visited[neighbor] && dfsCycleDetect(neighbor, visited, recStack) || recStack[neighbor]) {
                return true;
            }
        }

        // Remove the vertex from the recursion stack
        recStack[v] = false;
        return false;
    }

    // Function to check if the graph contains a cycle
    bool hasCycle_directed() {
        vector<bool> visited(V, false); // Mark all vertices as not visited
        vector<bool> recStack(V, false); // Recursion stack

        // Call the recursive helper function to detect cycle
        for (int i = 0; i < V; i++) {
            if (!visited[i] && dfsCycleDetect(i, visited, recStack)) { // Process unvisited nodes
                return true; // Cycle found
            }
        }
        return false; // No cycle found
    }
    
    // Function to detect cycle using DFS
    bool hasCycle_undirected() {
        vector<bool> visited(V, false);

        // Check for cycle in each component of the graph
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfsCycleDetect(i, visited, -1)) {
                    return true;
                }
            }
        }
        return false;
    }

    // Helper function to detect cycle using DFS from a given node
    bool dfsCycleDetect(int v, vector<bool> &visited, int parent) {
        visited[v] = true;

        // Check all adjacent vertices
        for (int neighbor : adj[v]) {
            // If the neighbor hasn't been visited, recursively visit it
            if (!visited[neighbor]) {
                if (dfsCycleDetect(neighbor, visited, v)) {
                    return true;
                }
            }
            // If the neighbor is visited and is not the parent, there is a cycle
            else if (neighbor != parent) {
                return true;
            }
        }
        return false;
    }

    bool hasCycle() {
        return directed ? hasCycle_directed() : hasCycle_undirected();
    }
};

int main() {
    Graph g(6,true);  // Example graph with 5 vertices

    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.BFS(3);  // Perform BFS starting from vertex 0
    g.DFS(3);  // Perform DFS starting from vertex 0
    g.topologicalSort();
    g.topologicalSortDeparture();
    return 0;
}
