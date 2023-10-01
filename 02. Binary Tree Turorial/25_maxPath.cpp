/*
Given a non-empty binary tree, find the maximum path.
----------------------------------------------------------------
Time : O(n)
Space: O(1)
*/
#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int result = INT_MIN;
    
    int maxPathSum(TreeNode* root) {
        maxSum(root);
        return result;
    }
    
    int maxSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        int left = max(0, maxSum(root->left));
        int right = max(0, maxSum(root->right));
        
        result = max(result, left + right + root->val);
        
        return max(left, right) + root->val;
    }
};

int main() {
    Solution solution;

    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(2);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(-25);
    root->right->right->left = new TreeNode(3);
    root->right->right->right = new TreeNode(4);

    cout << "Maximum Path Sum: " << solution.maxPathSum(root) << endl;

    return 0;
}
