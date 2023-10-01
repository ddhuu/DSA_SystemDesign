/*
Given a Binary Tree, determine if it  is a valid Binary Search Tree.
*/

#include <iostream>
#include <climits>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool checkBST(Node* node, int minVal, int maxVal) {
    if (node == nullptr) {
        return true;
    }
    
    if (node->data <= minVal || node->data >= maxVal) {
        return false;
    }
    
    return checkBST(node->left, minVal, node->data) && checkBST(node->right, node->data, maxVal);
}

bool isBST(Node* root) {
    return checkBST(root, INT_MIN, INT_MAX);
}

int main() {
    // Create a sample binary tree
    Node* root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);
    
    bool isValidBST = isBST(root);
    
    if (isValidBST) {
        std::cout << "The given tree is a valid Binary Search Tree." << std::endl;
    } else {
        std::cout << "The given tree is not a valid Binary Search Tree." << std::endl;
    }
    
    return 0;
}
