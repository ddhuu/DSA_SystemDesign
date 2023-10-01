/*
Given an array A[] of N positive integers. The task is to find the 
maximum of j - i with the constraint of A[i] <= A[j]
----------------------------------------------------------------
Time : O(n)
Space : O(n)
*/


//github.com/ddhuu
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximumDifference(vector<int>& nums) {
    int n = nums.size();
    vector<int> leftMin(n);
    
    leftMin[0] = nums[0];
    for (int i = 1; i < n; i++) {
        leftMin[i] = min(leftMin[i - 1], nums[i]);
    }

    int maxDiff = -1;
    for (int i = 1; i < n; i++) {
        if (nums[i] > leftMin[i - 1]) {
            maxDiff = max(maxDiff, nums[i] - leftMin[i - 1]);
        }
    }

    return maxDiff;
}

int main() {
    vector<int> nums = {7, 1, 5, 4};
    int maxDiff = maximumDifference(nums);

    cout << "Maximum Difference: " << maxDiff << endl;

    return 0;
}
