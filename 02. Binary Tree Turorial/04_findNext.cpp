/*
Given a binary tree and a key. Find the node right to the given key. If there is no node
in the right side, then return nullptr.
----------------------------------------------------------------
Time: O(n)
Space: O(1)
*/

#include <iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int _data) : data(_data), left(nullptr), right(nullptr) {}
};

Node* findRightNode(Node* node, int value, int level, int desiredLevel) {
    if (node == nullptr) {
        return nullptr;
    }

    if (node->data == value) {
        desiredLevel = level;
        return nullptr;
    }

    if (desiredLevel != 0) {
        if (level == desiredLevel) {
            return node;
        }
    }

    Node* left = findRightNode(node->left, value, level + 1, desiredLevel);
    if (left != nullptr) {
        return left;
    }

    return findRightNode(node->right, value, level + 1, desiredLevel);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int valueToFind = 5;
    int desiredLevel = 0;

    Node* result = findRightNode(root, valueToFind, 1, desiredLevel);

    if (result != nullptr) {
        std::cout << "Right node of value " << valueToFind << ": " << result->data << std::endl;
    } else {
        std::cout << "No right node found for value " << valueToFind << std::endl;
    }

    return 0;
}
