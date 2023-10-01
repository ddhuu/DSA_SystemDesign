/*
A height-balanced tree is defined as: a binary tree in which the left and the right subtrees 
of every node differ in height by no more than 1.
*/
#include <iostream>
#include <cstdlib> 

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int _data) : data(_data), left(nullptr), right(nullptr) {}
};

int findHeight(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    int leftHeight = findHeight(node->left);
    int rightHeight = findHeight(node->right);
    return 1 + std::max(leftHeight, rightHeight);
}

bool isTreeBalanced(Node* node) {
    if (node == nullptr) {
        return true;
    }

    int leftHeight = findHeight(node->left);
    int rightHeight = findHeight(node->right);

    if (abs(leftHeight - rightHeight) <= 1 &&
        isTreeBalanced(node->left) && isTreeBalanced(node->right)) {
        return true;
    }

    return false;
}

int main() {
    // Create a sample Binary Tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    if (isTreeBalanced(root)) {
        std::cout << "The tree is balanced." << std::endl;
    } else {
        std::cout << "The tree is not balanced." << std::endl;
    }

    return 0;
}
