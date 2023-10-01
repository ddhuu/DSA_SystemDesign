/*
Two nodes of a binary tree are cousins if they have the same depth, but
have different parents.
*/
#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int findDepth(Node* root, Node* node, int level) {
    if (root == nullptr) {
        return 0;
    }
    
    if (root->data == node->data) {
        return level;
    }
    
    int left = findDepth(root->left, node, level + 1);
    if (left != 0) {
        return left;
    }
    
    return findDepth(root->right, node, level + 1);
}

bool sameParents(Node* root, Node* node1, Node* node2) {
    if (root == nullptr) {
        return false;
    }
    
    return ((root->left == node1 && root->right == node2) || (root->right == node1 && root->left == node2));
}

bool areCousins(Node* root, Node* node1, Node* node2) {
    if (root == nullptr || node1 == nullptr || node2 == nullptr) {
        return false;
    }
    
    return (findDepth(root, node1, 1) == findDepth(root, node2, 1)) && !sameParents(root, node1, node2);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Node* node1 = root->left->left; // Node 4
    Node* node2 = root->right->right; // Node 7

    if (areCousins(root, node1, node2)) {
        std::cout << "Nodes " << node1->data << " and " << node2->data << " are cousins." << std::endl;
    } else {
        std::cout << "Nodes " << node1->data << " and " << node2->data << " are not cousins." << std::endl;
    }

    return 0;
}
