#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Graph {
private:
    int vertex;
    unordered_map<int, vector<int>> map;
    vector<int> node;

public:
    Graph(int v) : vertex(v), node(v, 0) {}

    void addEdge(int i, int j) {
        map[i].push_back(j);
        node[j]++;
    }

    void checkVertex() {
        for (int i = 0; i < vertex; i++) {
            if (node[i] == 0) {
                cout << i << " ";
                topological(i);
            }
        }
    }

    void topological(int i) {
        int size = map[i].size();
        for (int k = 0; k < size; k++) {
            node[map[i][k]]--;
            if (node[map[i][k]] == 0) {
                cout << map[i][k] << " ";
                topological(map[i][k]);
            }
        }
        node[i] = -1;
    }
};

int main() {
    int numVertices = 6;
    Graph g(numVertices);

    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Topological Sort: ";
    g.checkVertex();

    return 0;
}
