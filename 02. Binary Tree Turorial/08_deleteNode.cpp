/*
Delete the node with the given key in the BST
*/




#include <iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int _data) : data(_data), left(nullptr), right(nullptr) {}
};

Node* inOrderSuccessor(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

Node* Delete(Node* root, int value) {
    if (root == nullptr) {
        return root;
    } else if (root->data > value) {
        root->left = Delete(root->left, value);
    } else if (root->data < value) {
        root->right = Delete(root->right, value);
    } else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
            return nullptr;
        } else if (root->right == nullptr) {
            Node* temp = root;
            root = root->left;
            delete temp;
            return root;
        } else if (root->left == nullptr) {
            Node* temp = root;
            root = root->right;
            delete temp;
            return root;
        } else {
            Node* temp = inOrderSuccessor(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}

void inOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inOrderTraversal(root->left);
    std::cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    std::cout << "Original Tree: ";
    inOrderTraversal(root);
    std::cout << std::endl;

    int valueToDelete = 3;
    root = Delete(root, valueToDelete);

    std::cout << "Tree after deleting " << valueToDelete << ": ";
    inOrderTraversal(root);
    std::cout << std::endl;

    return 0;
}
