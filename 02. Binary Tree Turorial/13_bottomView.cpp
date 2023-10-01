/*
Given  a binary Tree, print the values of nodes which would be present in bottom of view
of binary tree.
*/
#include <iostream>
#include <unordered_map>

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Definition for a NodeLevel object
struct NodeLevel {
    int value;
    int level;
    NodeLevel(int val, int lvl) : value(val), level(lvl) {}
};

class Solution {
public:
    void bottomView(TreeNode* root, int level, int d, std::unordered_map<int, NodeLevel>& map) {
        if (root == nullptr) {
            return;
        }
        
        if (map.find(d) == map.end()) {
            NodeLevel obj(root->val, level);
            map[d] = obj;
        } else if (map[d].level < level) {
            map[d].value = root->val;
            map[d].level = level;
        }
        
        bottomView(root->left, level + 1, d - 1, map);
        bottomView(root->right, level + 1, d + 1, map);
    }
    
    void printBottomView(TreeNode* root) {
        std::unordered_map<int, NodeLevel> map;
        bottomView(root, 0, 0, map);
        
        for (const auto& entry : map) {
            std::cout << entry.second.value << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Solution solution;
    
    // Example binary tree creation
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(8);
    root->right = new TreeNode(22);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(25);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(14);

    // Print the bottom view
    solution.printBottomView(root);

    return 0;
}
