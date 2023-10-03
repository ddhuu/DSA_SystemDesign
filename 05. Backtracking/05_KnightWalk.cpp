#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int x, y;
    int dis;
    Node(int x, int y, int dis) : x(x), y(y), dis(dis) {}
};

int row[] = {2, 2, -2, -2, 1, 1, -1, -1};
int col[] = {-1, 1, 1, -1, 2, -2, 2, -2};

bool validPosition(int x, int y, int N) {
    return (x >= 0 && y >= 0 && x < N && y < N);
}

int knightWalk(int N, Node start, Node end) {
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    queue<Node> q;
    q.push(start);
    visited[start.x][start.y] = true;

    while (!q.empty()) {
        Node node = q.front();
        q.pop();

        if (node.x == end.x && node.y == end.y) {
            return node.dis; // Minimum steps to reach the destination
        }

        for (int i = 0; i < 8; i++) {
            int x = node.x + row[i];
            int y = node.y + col[i];

            if (validPosition(x, y, N) && !visited[x][y]) {
                visited[x][y] = true;
                q.push(Node(x, y, node.dis + 1));
            }
        }
    }

    return -1; // If the destination cannot be reached
}

int main() {
    int N = 8; // Size of the chessboard
    Node start(2, 3, 0); // Starting position
    Node end(7, 7, 0); // Destination position

    int minSteps = knightWalk(N, start, end);

    if (minSteps != -1) {
        cout << "Minimum steps to reach the destination: " << minSteps << endl;
    } else {
        cout << "The destination cannot be reached." << endl;
    }

    return 0;
}
