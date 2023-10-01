/*
 Matrix m*n is given, where all elements in any individual row or column 
are sorted. Write an algorhitm to retutn the existing of an element in that matrix.
----------------------------------------------------------------
Time: O(n)
Space: O(1) 
*/


//github.com/ddhuu
#include <iostream>

bool searchMatrix(int matrix[][3], int m, int n, int target) {
    int i = 0, j = n - 1;

    while (i < m && j >= 0) {
        if (matrix[i][j] == target) {
            return true;
        } else if (matrix[i][j] > target) {
            j--;
        } else {
            i++;
        }
    }
    
    return false;
}

int main() {
    int matrix[][3] = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };
    int m = sizeof(matrix) / sizeof(matrix[0]); // Number of rows
    int n = sizeof(matrix[0]) / sizeof(matrix[0][0]); // Number of columns
    int target = 5;

    bool found = searchMatrix(matrix, m, n, target);

    if (found) {
        std::cout << "Target found in the matrix." << std::endl;
    } else {
        std::cout << "Target not found in the matrix." << std::endl;
    }

    return 0;
}
