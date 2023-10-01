/*
Printing the left view of a binary tree involves printing the left-most node at each level
----------------------------------------------------------------
Time : O(n)
Space: O(n)
*/
#include <iostream>
#include <algorithm>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int first_node_level = 0;

void printLeftView(Node* node, int level) {
    if (node == nullptr) {
        return;
    }
    
    if (first_node_level < level) {
        std::cout << node->data << " ";
        first_node_level = level;
    }
    
    printLeftView(node->left, level + 1);
    printLeftView(node->right, level + 1);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    std::cout << "Left view of the binary tree: ";
    printLeftView(root, 1);
    
    return 0;
}
