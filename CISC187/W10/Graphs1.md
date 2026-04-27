Graphs 1 / Shada Elghariani / CISC187


# Task 1: Theoretical Graph
      A
     / \
    B   C
     \ /
      D
      |
      E
- This is an undirected graph with 5 vertices; A, B, C, D, and E. 
Each vertex represents a node, and each edge represents a connection between nodes.
This graph shows how nodes are linked together through edges.

# Task 2: Graph Implementation with BFS and DFS
``` cpp
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj;

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    // Breadth-First Search
    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal: ";

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << char(current + 'A') << " ";

            for (int neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    // Depth-First Search
    void DFS(int start) {
        vector<bool> visited(V, false);
        stack<int> s;

        s.push(start);

        cout << "DFS Traversal: ";

        while (!s.empty()) {
            int current = s.top();
            s.pop();

            if (!visited[current]) {
                cout << char(current + 'A') << " ";
                visited[current] = true;

                for (int neighbor : adj[current]) {
                    if (!visited[neighbor]) {
                        s.push(neighbor);
                    }
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g(5);

    // A=0, B=1, C=2, D=3, E=4
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.BFS(0);
    g.DFS(0);

    return 0;
}
```

## - Explanation of BFS

- Breadth-First Search or (BFS) uses a **queue** to explore the graph level by level.

Steps:
1. It starts at a vertex.
2. Visits all its neighbors.
3. Then it visits the neighbors of the neighbors.

Example traversal that starts at A: A → B → C → D → E

BFS is useful for finding the shortest path in an unweighted graph.


## - Explanation of DFS

- Depth-First Search also known as DFS, uses a **stack** to explore as far as possible before backtracking.

Steps:

1. Also starts at a vertex.
2. Goes as deep as possible along one path.
3. Backtracks when no more nodes are available.

Example traversal: A → C → D → E → B

DFS is useful for exploring all possible paths.

# Task 3: Comparison with Big-O Notation

Time Complexity: both BFS and DFS have a time complexity of O(V + E). V is the number of vertices and E is the number of edges. This is because each vertex is visited once and each edge is also explored once.

BFS explores nodes level by level using a queue and is useful for finding the shortest paths. 
DFS explores deeply using a stack and is useful for exploring all paths.
