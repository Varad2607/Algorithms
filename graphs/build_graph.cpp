#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to build a graph from edges
unordered_map<int, vector<int>> buildGraph(const vector<pair<int, int>>& edges, bool isUndirected = true) {
    unordered_map<int, vector<int>> graph;

    for (const auto& edge : edges) {
        int x = edge.first;
        int y = edge.second;

        // Add edge from x to y
        graph[x].push_back(y);

        // Add edge from y to x if the graph is undirected
        if (isUndirected) {
            graph[y].push_back(x);
        }
    }

    return graph;
}

// Function to display the graph (for debugging purposes)
void displayGraph(const unordered_map<int, vector<int>>& graph) {
    for (const auto& node : graph) {
        cout << "Node " << node.first << " -> ";
        for (int neighbor : node.second) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

int main() {
    // Example edges
    vector<pair<int, int>> edges = {
        {0, 1}, {0, 2}, {1, 2}, {3, 4}
    };

    // Build graph
    unordered_map<int, vector<int>> graph = buildGraph(edges, true);

    // Display the graph
    displayGraph(graph);

    return 0;
}
