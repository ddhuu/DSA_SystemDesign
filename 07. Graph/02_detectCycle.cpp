#include <iostream>
#include <map>
#include <list>
#include <vector>

using namespace std;

class Graph {
    int data;
    map<int, list<int>> map;
    int flag = 0;

public:
    Graph(int vertex) {
        for (int i = 0; i < vertex; i++)
            map[i] = list<int>();
    }

    void addEdge(int i, int j) {
        map[i].push_back(j);
        map[j].push_back(i); // For undirected graph
    }

    bool isCyclicPresent() {
        vector<bool> visited(data, false);

        for (const auto& it : map) {
            int vertex = it.first;
            if (!visited[vertex]) {
                if (isCyclicUtil(vertex, visited, -1))
                    return true;
            }
        }
        return false;
    }

private:
    bool isCyclicUtil(int index, vector<bool>& visited, int parent) {
        visited[index] = true;

        for (const auto& neighbor : map[index]) {
            if (!visited[neighbor]) {
                if (isCyclicUtil(neighbor, visited, index))
                    return true;
            } else if (neighbor != parent) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    int vertex = 5;
    Graph g(vertex);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(1, 3);
    g.addEdge(3, 4);

    if (g.isCyclicPresent()) {
        cout << "The graph contains a cycle." << endl;
    } else {
        cout << "The graph does not contain a cycle." << endl;
    }

    return 0;
}
