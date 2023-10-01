/*
The diameter of a binary tree is the longest path between any two nodes in a tree.
----------------------------------------------------------------
Time: O(n)
*/
#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int diameter = 0;
    int max_diameter = 0;

    int findDiameter(Node* root) {
        if (root == nullptr) {
            return 0;
        }

        int left_height = findDiameter(root->left);
        int right_height = findDiameter(root->right);
        diameter = left_height + right_height + 1;

        if (diameter > max_diameter) {
            max_diameter = diameter;
        }

        return 1 + std::max(left_height, right_height);
    }
};

int main() {
    Solution solution;

    // Create your binary tree here
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    solution.findDiameter(root);
    std::cout << "Diameter of the tree: " << solution.max_diameter << std::endl;

    return 0;
}
