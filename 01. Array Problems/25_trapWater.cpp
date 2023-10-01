/*
N non-negative integers representing an elevation map where the width of each bar is 1. 
Write an algorithm to find how much water it is able to trap after raining.
----------------------------------------------------------------
Time : O(n)
Space: O(n)
*/


//github.com/ddhuu
#include <iostream>
#include <vector>

using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    if (n == 0) {
        return 0;
    }

    vector<int> maxLeft(n);
    vector<int> maxRight(n);

    maxLeft[0] = height[0];
    for (int i = 1; i < n; i++) {
        maxLeft[i] = max(maxLeft[i - 1], height[i]);
    }

    maxRight[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        maxRight[i] = max(maxRight[i + 1], height[i]);
    }

    int sum = 0;

    for (int i = 0; i < n; i++) {
        int waterHeight = min(maxLeft[i], maxRight[i]);
        if (waterHeight > height[i]) {
            sum += waterHeight - height[i];
        }
    }

    return sum;
}

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int trappedWater = trap(height);

    cout << "Trapped Rainwater Amount: " << trappedWater << endl;

    return 0;
}
