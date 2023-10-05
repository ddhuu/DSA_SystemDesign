#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // Right, Down, Left, Up

bool isValid(int i, int j, int numRows, int numCols) {
    return i >= 0 && i < numRows && j >= 0 && j < numCols;
}

bool DFSTraversalInMatrix(vector<vector<int>>& matrix, int i, int j) {
    int numRows = matrix.size();
    int numCols = matrix[0].size();
    
    // Base case: If we reach the bottom right corner, return true
    if (i == numRows - 1 && j == numCols - 1) {
        return true;
    }
    
    // Mark the current cell as visited
    matrix[i][j] = -1;
    
    // Try to move in all four directions
    for (vector<int>& dir : dirs) {
        int newRow = i + dir[0];
        int newCol = j + dir[1];
        
        if (isValid(newRow, newCol, numRows, numCols) && matrix[newRow][newCol] == 0) {
            if (DFSTraversalInMatrix(matrix, newRow, newCol)) {
                return true;
            }
        }
    }
    
    // Restore the cell to its original value (backtrack)
    matrix[i][j] = 0;
    
    return false;
}

bool findPath(vector<vector<int>>& matrix) {
    return DFSTraversalInMatrix(matrix, 0, 0);
}

int main() {
    // Example usage:
    vector<vector<int>> matrix = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0}
    };

    if (findPath(matrix)) {
        cout << "A valid path exists from top-left to bottom-right." << endl;
    } else {
        cout << "No valid path exists." << endl;
    }

    return 0;
}
