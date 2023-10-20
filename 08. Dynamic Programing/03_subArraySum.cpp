#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1; // Initialize for the empty subset.
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                if (j >= nums[i - 1]) {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return dp[n][k];
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 1};
    int k = 2;
    int result = solution.subarraySum(nums, k);
    
    cout << "The number of subsets with sum " << k << " is: " << result << endl;

    return 0;
}
