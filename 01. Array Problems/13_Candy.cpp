/*
There are N children standing in a line with some rating value. You want 
to distribute a minimum number of candies to these children such that: 
->Each child must have at least one candy. 
->The children with higher ratings will have more candies than their neighbors.
*/


//github.com/ddhuu
#include <iostream>
#include<vector>
#include <algorithm>


int sumCandy(int ratings[], int n) {
  
    std::vector<int> left(n,1);
    std::vector<int> right(n,1);
    int sum = 0;

    // Calculate candies given to the right neighbors
    for (int i = 1; i < n; i++) {
        if (ratings[i - 1] < ratings[i]) {
            left[i] = left[i - 1] + 1;
        }
    }

    // Calculate candies given to the left neighbors
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i + 1] < ratings[i]) {
            right[i] = right[i + 1] + 1;
        }
    }

    // Calculate the total sum of candies
    for (int i = 0; i < n; i++) {
        sum += std::max(left[i], right[i]);
    }

    return sum;
}

int main() {
    int ratings[] = {1, 1, 2};
    int n = sizeof(ratings) / sizeof(ratings[0]);

    int result = sumCandy(ratings, n);

    std::cout << "Maximum number of candies required: " << result << std::endl;

    return 0;
}
