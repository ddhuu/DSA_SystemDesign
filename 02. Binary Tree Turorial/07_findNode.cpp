/*
Print all the nodes which are at k distance from the root
----------------------------------------------------------------
Time : O(n)
*/




#include <iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int _data) : data(_data), left(nullptr), right(nullptr) {}
};

void findNode(Node* node, int k) {
    if (node == nullptr) {
        return;
    }

    if (k == 0) {
        std::cout << node->data << std::endl;
    } else {
        findNode(node->left, k - 1);
        findNode(node->right, k - 1);
    }
}

int main() {
    // Create a sample Binary Tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int k = 2; // Specify the level

    std::cout << "Nodes at level " << k << ": ";
    findNode(root, k);

    return 0 ;
}
