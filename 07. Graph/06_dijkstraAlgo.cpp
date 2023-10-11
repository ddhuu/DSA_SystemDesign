#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;

class Node {
public:
    int prev;
    int distanceSource;

    Node(int p, int d) : prev(p), distanceSource(d) {}
};

class PriorityQ {
public:
    int distance;
    int current;

    PriorityQ(int c, int d) : current(c), distance(d) {}
};

class Dijkstra {
public:
    Dijkstra(int vertices) {
        visited = vector<bool>(vertices, false);
        map = unordered_map<int, Node>();
        pq = priority_queue<PriorityQ, vector<PriorityQ>, greater<PriorityQ>>();
    }

    void addEdge(int source, int destination, int weight) {
        edges[source].push_back({destination, weight});
        edges[destination].push_back({source, weight});
    }

    void dijkstra(int startVertex) {
        map[startVertex] = Node(-1, 0); // Set source distance to 0
        pq.push(PriorityQ(startVertex, 0));

        while (!pq.empty()) {
            int currentVertex = pq.top().current;
            int currentDistance = pq.top().distance;
            pq.pop();

            if (visited[currentVertex]) {
                continue;
            }

            visited[currentVertex] = true;

            for (const auto &edge : edges[currentVertex]) {
                int adjacentVertex = edge.first;
                int edgeWeight = edge.second;

                if (currentDistance + edgeWeight < map[adjacentVertex].distanceSource) {
                    map[adjacentVertex] = Node(currentVertex, currentDistance + edgeWeight);
                    pq.push(PriorityQ(adjacentVertex, currentDistance + edgeWeight));
                }
            }
        }
    }

    void printShortestPaths() {
        for (const auto &entry : map) {
            int vertex = entry.first;
            Node data = entry.second;
            if (data.prev != -1) {
                cout << "Shortest path to vertex " << vertex << " from vertex " << data.prev << " has distance " << data.distanceSource << endl;
            }
        }
    }

private:
    vector<bool> visited;
    unordered_map<int, Node> map;
    priority_queue<PriorityQ, vector<PriorityQ>, greater<PriorityQ>> pq;
    vector<pair<int, int>> edges[1001];
};

int main() {
    int vertices = 5;
    Dijkstra graph(vertices);

    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 3, 4);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 2);
    graph.addEdge(2, 3, 5);
    graph.addEdge(2, 4, 1);
    graph.addEdge(3, 4, 3);

    int startVertex = 0;
    graph.dijkstra(startVertex);
    graph.printShortestPaths();

    return 0;
}
