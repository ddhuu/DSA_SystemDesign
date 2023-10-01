/*
Given  a binary Tree, find the lowest common ancestor (LCA) of two given Nodes.
*/
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int lowestCommonAncestor(TreeNode* root, int data1, int data2) {
        if (root == nullptr) {
            return 0;
        }
        
        if (root->val == data1 || root->val == data2) {
            return root->val;
        }
        
        int left = lowestCommonAncestor(root->left, data1, data2);
        int right = lowestCommonAncestor(root->right, data1, data2);
        
        if (left != 0 && right != 0) {
            std::cout << root->val << std::endl;
            exit(0); // Terminate the program
        }
        
        if (left != 0) {
            return left;
        }
        
        if (right != 0) {
            return right;
        }
        
        return 0;
    }
};

int main() {
    Solution solution;

    // Example binary tree creation
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    int data1 = 5, data2 = 1;
    int result = solution.lowestCommonAncestor(root, data1, data2);

    std::cout << "Lowest Common Ancestor: " << result << std::endl;

    return 0;
}

