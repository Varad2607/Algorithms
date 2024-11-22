#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

// Define a Node struct for better organization
struct Node {
    int x, y;      // Coordinates
    float g;       // Cost from start to the current node
    float h;       // Heuristic cost to the goal
    float f;       // f = g + h

    Node(int x, int y, float g, float h) : x(x), y(y), g(g), h(h) {
        f = g + h;
    }
};

class Star {
private:
    vector<Node> openList;           // Open list to store nodes for evaluation
    vector<vector<int>> grid;        // Grid representation (0 = free cell, 1 = obstacle)
    pair<int, int> goal;             // Goal coordinates

public:
    // Constructor
    Star(const vector<vector<int>>& grid, pair<int, int> goal) 
        : grid(grid), goal(goal) {}

    // Sorts the open list based on f = g + h
    void CellSort() {
        sort(openList.begin(), openList.end(), [](const Node& a, const Node& b) {
            return a.f < b.f;
        });
    }

    // Expands neighbors for the current node
    void ExpandNeighbors(const Node& current) {
        static const vector<pair<int, int>> directions = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1} // Up, Down, Left, Right
        };

        for (const auto& dir : directions) {
            int newX = current.x + dir.first;
            int newY = current.y + dir.second;

            if (CheckValidCell(newX, newY)) {
                float newG = current.g + 1.0; // Assuming uniform cost
                float newH = Heuristic(newX, newY);
                AddToOpen(newX, newY, newG, newH);
            }
        }
    }

    // Ensures the cell is within bounds and not an obstacle
    bool CheckValidCell(int x, int y) const {
        return x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == 0;
    }

    // Computes the heuristic (Manhattan distance in this example)
    float Heuristic(int x, int y) const {
        return abs(x - goal.first) + abs(y - goal.second);
    }

    // Adds a node to the open list
    void AddToOpen(int x, int y, float g, float h) {
        openList.emplace_back(x, y, g, h);
    }

    // Displays the open list (for debugging)
    void DisplayOpenList() const {
        for (const auto& node : openList) {
            cout << "Node(" << node.x << ", " << node.y << ") -> g: " << node.g
                 << ", h: " << node.h << ", f: " << node.f << endl;
        }
    }
};

int main() {
    // Example usage
    vector<vector<int>> grid = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0},
    };

    pair<int, int> goal = {4, 4};
    Star aStar(grid, goal);

    // Start node
    Node start(0, 0, 0, aStar.Heuristic(0, 0));
    aStar.AddToOpen(start.x, start.y, start.g, start.h);

    // Simulate one expansion
    aStar.ExpandNeighbors(start);
    aStar.CellSort();  // Sort the open list based on f = g + h

    // Display open list
    aStar.DisplayOpenList();

    return 0;
}
