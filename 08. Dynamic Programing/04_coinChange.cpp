#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1; // Initialize for the empty subset.
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (j >= coins[i - 1]) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][amount];
    }
};

int main() {
    Solution solution;
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    int result = solution.change(amount, coins);

    cout << "The total number of distinct ways to make change is: " << result << endl;

    return 0;
}
//multithreading and synchronization

