#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

class Graph {
public:
    Graph(int vertices);
    void addEdge(int u, int v, int weight);
    void kruskalMST();
    void printGraph();

private:
    int vertices;
    std::vector<std::tuple<int, int, int>> edges;  // (weight, u, v)
    int find(int u, std::vector<int>& parent);
    void unionSets(int u, int v, std::vector<int>& parent, std::vector<int>& rank);
};

Graph::Graph(int vertices) : vertices(vertices) {}
void Graph::printGraph() {
    std::cout << "(u, v , weight)" << std::endl;
    for (int i = 0; i < edges.size(); i++) {
        std::cout << "( " << std::get<1>(edges[i]) << ", " << std::get<2>(edges[i]) << ", " << std::get<0>(edges[i]) << ") " << std::endl;
    }
    std::cout << std::endl << std::endl;
}

void Graph::addEdge(int u, int v, int weight) {
    edges.emplace_back(weight, u, v);
}
int Graph::find(int u, std::vector<int>& parent) {
    if (u != parent[u]) {
        parent[u] = find(parent[u], parent);
    }
    return parent[u];
}

void Graph::unionSets(int u, int v, std::vector<int>& parent, std::vector<int>& rank) {
    int rootU = find(u, parent);
    int rootV = find(v, parent);

    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        }
        else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        }
        else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

void Graph::kruskalMST() {
    std::vector<std::tuple<int, int, int>> mst;  // Minimal Spanning Tree
    std::sort(edges.begin(), edges.end(), [](std::tuple<int, int, int>& a, std::tuple<int, int, int>& b) { return std::get<0>(a) < std::get<0>(b); });  // Sort edges by weight

    std::vector<int> parent(vertices);
    std::vector<int> rank(vertices, 0);

    for (int i = 0; i < vertices; ++i) {
        parent[i] = i;
    }

    for (int i = 0; i < edges.size(); i++) { 
        int rootU = find(std::get<1>(edges[i]), parent);
        int rootV = find(std::get<2>(edges[i]), parent);

        if (rootU != rootV) {
            mst.emplace_back(std::get<0>(edges[i]), std::get<1>(edges[i]), std::get<2>(edges[i]));
            unionSets(rootU, rootV, parent, rank);
        }
    }

    std::cout << "Aristas para MST:\n";
    for (int i = 0; i < mst.size(); i++) {
        std::cout << std::get<1>(mst[i]) << " - " << std::get<2>(mst[i]) << " (weight: " << std::get<0>(mst[i]) << ")\n";
    }
}


int main() {
    Graph g(9);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 4);
    g.addEdge(1, 2, 7);
    g.addEdge(1, 7, 12);
    g.addEdge(2, 4, 3);
    g.addEdge(2, 6, 4);
    g.addEdge(2, 3, 8);
    g.addEdge(3, 5, 9);
    g.addEdge(4, 7, 5);
    g.addEdge(5, 6, 7);
    g.addEdge(5, 8, 10);
    g.addEdge(6, 8, 6);
    g.addEdge(6, 7, 5);
    g.addEdge(7, 8, 11);

    g.printGraph();
    g.kruskalMST();

}
