#include <iostream>
#include <climits>
using namespace std;
#define V 5  // Number of vertices

// Function to find index of the minimum-weight vertex from the set of unvisited vertices
int findMinVertex(bool visited[], int weights[]) {
    int index = -1;   // Index of the vertex with the smallest weight
    int minW = INT_MAX;

    for (int i = 0; i < V; i++) {
        if (!visited[i] && weights[i] < minW) {
            minW = weights[i];
            index = i;
        }
    }
    return index;
}

// Utility function to print the minimum spanning tree (MST)
void printMinimumSpanningTree(int graph[V][V], int parent[]) {
    int MST_weight = 0;
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
        MST_weight += graph[i][parent[i]];
    }
    cout << "\nWeight of the minimum spanning tree: " << MST_weight << '\n';
}

// Function to find the minimum spanning tree using Prim's Algorithm
void primMST(int graph[V][V]) {
    bool visited[V];         // Tracks visited vertices
    int weights[V];          // Stores the minimum weight to connect each vertex
    int parent[V];           // Stores the parent node of each vertex

    // Initialize arrays
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        weights[i] = INT_MAX;
    }

    // Start from the first vertex
    weights[0] = 0;  // Make the first vertex weight 0
    parent[0] = -1;  // The first vertex is the root of the MST

    // Build the MST with (V-1) edges
    for (int i = 0; i < V - 1; i++) {
        int minVertexIndex = findMinVertex(visited, weights);  // Find the minimum weight vertex
        visited[minVertexIndex] = true;  // Mark it as visited

        // Update adjacent vertices
        for (int j = 0; j < V; j++) {
            if (graph[minVertexIndex][j] != 0 && !visited[j] && graph[minVertexIndex][j] < weights[j]) {
                weights[j] = graph[minVertexIndex][j];
                parent[j] = minVertexIndex;
            }
        }
    }

    // Print the constructed MST
    printMinimumSpanningTree(graph, parent);
}

// Driver Code
int main() {
    // Example graph represented by an adjacency matrix
    int graph[V][V] = {
        { 0, 2, 0, 6, 0 },
        { 2, 0, 3, 8, 5 },
        { 0, 3, 0, 0, 7 },
        { 6, 8, 0, 0, 9 },
        { 0, 5, 7, 9, 0 }
    };

    // Function call
    primMST(graph);

    return 0;
}
