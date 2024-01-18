# Dynamic Programing
## 01. Longest Common Subsequences
Given two strings of length m and n, find the length of their longest subsequence in Time Complexity and Space Complexity O(m*n).
## 02. Edit String Distance
Given two words word1 of length m and word2 of length n, find the minimum number of operations required to convert word1 to word2 in Time and Space Complexity O(mn). You have the following 3 operations permitted on a word: 1. Insert a character 2. Delete a character 3. Replace a character.
## 03. Sub Array sums equal K
Given an array [] of length N and an integer Sum , the task is to find the number of subsets with equal to sum. 
## 04. Coin Change
Given an unlimited supply of coins of given denominations, find the total number of distinct ways to get a desired change in Time and Space Complexity in O(n^2).
## 05. Maximum Profit in Jobs Scheduling
 We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].You're given the startTime, endTime and profit arrays, you need to output the maximum profit you can take such that there are no 2 jobs in the subset with an overlapping time range.If you choose a job that ends at time X you will be able to start another job that starts at time X
 ```cpp

1. Sort on the basis of finish time
2. Compare every two jobs whether they can overlap

using namespace std;

struct Job {
    int start, finish, profit;
};

bool jobComparator(Job s1, Job s2) {
    return (s1.finish < s2.finish);
}

int findLastNonConflictingJob(vector<Job>& jobs, int n) {
    for (int i = n - 1; i >= 0; i--) {
        if (jobs[i].finish <= jobs[n].start) {
            return i;
        }
    }
    return -1;
}

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<Job> jobs(n);
        for (int i = 0; i < n; i++) {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }
        sort(jobs.begin(), jobs.end(), jobComparator);
        vector<int> dp(n);
        dp[0] = jobs[0].profit;
        for (int i = 1; i < n; i++) {
            int inclProfit = jobs[i].profit;
            int l = findLastNonConflictingJob(jobs, i);
            if (l != -1) {
                inclProfit += dp[l];
            }
            dp[i] = max(inclProfit, dp[i - 1]);
        }
        return dp[n - 1];
    }
};

 ```

 ## 06. Longest Palindromic Subsequence
 The Longest Palindromic Subsequence (LPS) problem is the problem of finding the longest subsequences of a string of length n that is also a palindrome In Time and Space Complexity of O(n^2).

```cpp
1. adceca -> 2 + LPS (dcec)
2. dceca -> max (LPS(dcec),LPS(ceca))
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
        return dp[0][n - 1];
    }
};

```