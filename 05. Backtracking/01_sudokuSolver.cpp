#include <iostream>

class Cell {
public:
    int x;
    int y;
};

bool isSafeNumber(int matrix[9][9], int i, int j, int num) {
    for (int x = 0; x < 9; ++x) {
        if (matrix[i][x] == num || matrix[x][j] == num) {
            return false;
        }
    }
    
    int rowStart = i - i % 3;
    int colStart = j - j % 3;
    for (int row = rowStart; row < rowStart + 3; ++row) {
        for (int col = colStart; col < colStart + 3; ++col) {
            if (matrix[row][col] == num) {
                return false;
            }
        }
    }
    
    return true;
}

Cell checkAnyUnassignedValue(int matrix[9][9]) {
    Cell c;
    c.x = -1;
    c.y = -1;
    
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (matrix[i][j] == 0) {
                c.x = i;
                c.y = j;
                return c;
            }
        }
    }
    
    return c;
}

bool sudokuProblem(int matrix[9][9]) {
    Cell c = checkAnyUnassignedValue(matrix);
    int i = c.x;
    int j = c.y;
    
    if (i == -1 && j == -1) {
        return true; // All cells are assigned
    }
    
    for (int num = 1; num <= 9; ++num) {
        if (isSafeNumber(matrix, i, j, num)) {
            matrix[i][j] = num;
            if (sudokuProblem(matrix)) {
                return true;
            }
            matrix[i][j] = 0; // Backtrack
        }
    }
    
    return false; // No solution found
}

void printSudoku(int matrix[9][9]) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int matrix[9][9] = {
        // Initialize your Sudoku puzzle here (0 for unassigned cells)
    };
    
    if (sudokuProblem(matrix)) {
        std::cout << "Sudoku solution:" << std::endl;
        printSudoku(matrix);
    } else {
        std::cout << "No solution exists for the Sudoku puzzle." << std::endl;
    }
    
    return 0;
}
