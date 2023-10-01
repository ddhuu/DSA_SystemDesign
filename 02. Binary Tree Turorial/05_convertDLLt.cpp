/*
Convert binary to doubly linked list such that the left pointer of the node should be pointing the the previous
node, and the right pointer should be pointing to the next node.
----------------------------------------------------------------
Time: O(n)
Space:  O(height)
*/

#include <iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int _data) : data(_data), left(nullptr), right(nullptr) {}
};

Node* parent = nullptr; // Global variable to keep track of the previous node
int flag = 0; // Global flag to check if it's the first node

void createLinkedList(Node* node) {
    if (node == nullptr) {
        return;
    }

    createLinkedList(node->left);

    if (flag == 0) {
        flag = 1;
        parent = node;
    } else {
        node->left = parent;
        parent->right = node;
        parent = node;
    }

    createLinkedList(node->right);
}

int main() {
    // Create a sample Binary Search Tree
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    // Convert BST to doubly linked list
    createLinkedList(root);

    // Traverse the linked list
    Node* current = root;
    std::cout << "Doubly Linked List: ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->right;
    }
    std::cout << std::endl;

    return 0;
}
