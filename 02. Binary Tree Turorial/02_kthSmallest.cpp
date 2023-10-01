/*
Find the kth Smallest in the BST
*/
#include <iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int count = 0;

int kthLargest(Node* node, int k) {
    if (node == nullptr) {
        return -1; // Return a value that indicates no kth largest element found
    }
    
    int result = kthLargest(node->right, k);
    
    if (result != -1) {
        return result;
    }
    
    count++;
    if (count == k) {
        return node->data;
    }
    
    return kthLargest(node->left, k);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(15);
    root->right->right = new Node(25);

    int k = 3; // Find the 3rd largest element

    int kthLargestValue = kthLargest(root, k);
    if (kthLargestValue != -1) {
        std::cout << "The " << k << "th largest element is: " << kthLargestValue << std::endl;
    } else {
        std::cout << "No kth largest element found!" << std::endl;
    }

    return 0;
}
