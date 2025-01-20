#include <iostream>
#include<vector>
using namespace std;

class UnionFind {
public:
    int*parent,*rank;
    int size;
    UnionFind(int n) :size(n){
        parent=new int[n];
        rank=new int[n]{};
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    ~UnionFind(){
        delete parent;
        delete rank;
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) {
            return false;
        }

        // Union by rank
        if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }

        return true;
    }
};

bool hasCycle(int n, vector<pair<int, int>>& edges) {
    UnionFind uf(n);

    for (auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;

        if (!uf.unionSets(u, v)) {
            return true;  // Cycle detected
        }
    }

    return false;  // No cycle found
}

int main() {
    int n = 4;  // Number of vertices
    vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};  // Graph edges

    if (hasCycle(n, edges)) {
        cout << "Graph contains a cycle" << endl;
    } else {
        cout << "Graph does not contain a cycle" << endl;
    }

    return 0;
}
