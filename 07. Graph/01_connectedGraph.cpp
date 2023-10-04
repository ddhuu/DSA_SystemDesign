#include <iostream>
#include <vector>

using namespace std;


class Graph {
public:
    int N; // Number of vertices
    vector<vector<int>> adjList;

    Graph(int n) : N(n) {
        adjList.resize(n);
    }
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    bool checkConnected() {
        vector<bool> visited(N, false);
        DFS(0, visited);

        for (bool b : visited) {
            if (!b) {
                return false;
            }
        }

        return true;
    }

private:
    void DFS(int v, vector<bool>& visited) {
        visited[v] = true;
        for (int u : adjList[v]) {
            if (!visited[u]) {
                DFS(u, visited);
            }
        }
    }
};

int main() {
    // Create a graph with 6 vertices
    Graph graph(6);

    // Add edges to the graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(4, 5);

    if (graph.checkConnected()) {
        cout << "The graph is connected." << endl;
    } else {
        cout << "The graph is not connected." << endl;
    }

    return 0;
}
