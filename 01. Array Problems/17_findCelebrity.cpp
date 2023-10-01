
/*
ou are in a party of N people, where only one person is known to 
everyone. Such a person may be present at the party, if yes, (s)he doesn’t know anyone at the 
party. 
Write the algorhitm to find the celebrity

----------------------------------------------------------------
Time : O(n)

*/

//github.com/ddhuu
#include <iostream>
#include <vector>

int findCelebrity(std::vector<std::vector<int>>& arr) {
    int X = 0;
    int Y = arr.size() - 1;

    while (X < Y) {
        if (arr[X][Y] == 1) {
            X++;
        } else {
            Y--;
        }
    }

    for (int i = 0; i < arr.size(); i++) {
        if (i != X && (arr[X][i] == 1 || arr[i][X] == 0)) {
            return -1; // No celebrity found
        }
    }

    return X; // X is the potential celebrity
}

int main() {
    // Example matrix indicating relationships (1: knows, 0: doesn't know)
    std::vector<std::vector<int>> matrix = {
        {0, 1, 0, 1},
        {0, 0, 0, 1},
        {1, 1, 0, 1},
        {0, 0, 0, 0}
    };

    int celebrity = findCelebrity(matrix);

    if (celebrity != -1) {
        std::cout << "Celebrity found at index: " << celebrity << std::endl;
    } else {
        std::cout << "No celebrity found." << std::endl;
    }

    return 0;
}
