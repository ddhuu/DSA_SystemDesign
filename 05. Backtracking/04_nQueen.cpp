#include <iostream>
using namespace std;

const int N = 8; // Define the size of the chessboard (8x8 in this example)

void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkSafePosition(int board[N][N], int row, int col) {
    // Check Rows on the left side
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    // Check Diagonal left size, upper position
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check Diagonal left size, lower position
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solveNQueens(int board[N][N], int col) {
    if (col >= N) {
        // All queens are placed successfully
        return true;
    }

    for (int row = 0; row < N; row++) {
        if (checkSafePosition(board, row, col)) {
            board[row][col] = 1; // Place the queen

            if (solveNQueens(board, col + 1)) {
                // If placing the queen in this position leads to a solution
                return true;
            }

            board[row][col] = 0; // Backtrack
        }
    }

    return false; // If no safe position is found in this column
}

int main() {
    int board[N][N] = {0}; // Initialize the chessboard

    if (solveNQueens(board, 0)) {
        cout << "Solution found:" << endl;
        printBoard(board);
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}
