#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    islands++;
                    queue<pair<int, int>> myQ;
                    myQ.push({i, j});
                    visited[i][j] = true;

                    while (!myQ.empty()) {
                        int x = myQ.front().first;
                        int y = myQ.front().second;
                        myQ.pop();

                        for (int k = 0; k < 4; k++) {
                            int newX = x + dx[k];
                            int newY = y + dy[k];

                            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols &&
                                grid[newX][newY] == '1' && !visited[newX][newY]) {
                                myQ.push({newX, newY});
                                visited[newX][newY] = true;
                            }
                        }
                    }
                }
            }
        }

        return islands;
    }
};

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    Solution solution;
    int islands = solution.numIslands(grid);
    cout << "Number of Islands: " << islands << endl;

    return 0;
}
