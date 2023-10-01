/*
Print all the boundary nodes in the Binary Tree ( anti Clockwise direction )
--------------------------------
Time : O(n)
*/



#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void leftInternal(Node* node) {
    if (node != nullptr) {
        if (node->left != nullptr) {
            cout << node->data << endl;
            leftInternal(node->left);
        } else if (node->right != nullptr) {
            cout << node->data << endl;
            leftInternal(node->right);
        }
    }
}

void leaveNodes(Node* node) {
    if (node != nullptr) {
        leaveNodes(node->left);
        if (node->left != nullptr && node->right != nullptr) {
            cout << node->data << endl;
        }
        leaveNodes(node->right);
    }
}

void rightInternal(Node* node) {
    if (node != nullptr) {
        if (node->right != nullptr) {
            rightInternal(node->right);
            cout << node->data << endl;
        } else if (node->left != nullptr) {
            rightInternal(node->left);
            cout << node->data << endl;
        }
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    leftInternal(root->left);
    leaveNodes(root);
    rightInternal(root->right);

  
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
