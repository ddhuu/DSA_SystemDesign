/*
Find the contiguous subarray within an array of length [n] which has the largest sum.
----------------------------------------------------------------
Time : O(n)
Space: O (1)
----------------------------------------------------------------
Kadane Algorithm

*/


//github.com/ddhuu
#include <iostream>
#include <climits>

int maxSubArray(int nums[], int n) {
    int result = INT_MIN, iResult = 0;

    for (int i = 0; i < n; i++) {
        iResult += nums[i];
        if (iResult < nums[i]) {
            iResult = nums[i];
        }
        if (result < iResult) {
            result = iResult;
        }
    }

    return result;
}

int main() {
    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(nums) / sizeof(nums[0]);

    int maxSum = maxSubArray(nums, n);
    
    std::cout << "Maximum subarray sum: " << maxSum << std::endl;

    return 0;
}
