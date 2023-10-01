/*
Traversal shemes
*/
#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void inOrder(Node* node) {
    if (node == nullptr) {
        return;
    }
    inOrder(node->left);
    std::cout << node->data << " ";
    inOrder(node->right);
}

void postOrder(Node* node) {
    if (node == nullptr) {
        return;
    }
    postOrder(node->left);
    postOrder(node->right);
    std::cout << node->data << " ";
}

void preOrder(Node* node) {
    if (node == nullptr) {
        return;
    }
    std::cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    std::cout << "In-order traversal: ";
    inOrder(root);
    std::cout << std::endl;

    std::cout << "Post-order traversal: ";
    postOrder(root);
    std::cout << std::endl;

    std::cout << "Pre-order traversal: ";
    preOrder(root);
    std::cout << std::endl;

    return 0;
}
