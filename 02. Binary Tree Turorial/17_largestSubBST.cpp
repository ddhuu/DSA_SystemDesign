/*
Given a binary tree, find the largest subtree which is a BST
*/
#include <iostream>
#include <algorithm>
#include <climits>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class List {
public:
    int size;
    int min;
    int max;
    bool isBST;
    List(){};
    List(int s, int mn, int mx, bool bst) : size(s), min(mn), max(mx), isBST(bst) {}
};

List largestBST(Node* root) {
    if (root == nullptr) {
        return List(0, INT_MIN, INT_MAX, true);
    }
    
    if (root->left == nullptr && root->right == nullptr) {
        return List(1, root->data, root->data, true);
    }
    
    List left = largestBST(root->left);
    List right = largestBST(root->right);
    List ret;
    
    ret.size = 1 + left.size + right.size;
    if (left.isBST && right.isBST && left.max < root->data && right.min > root->data) {
        ret.min = std::min(left.min, std::min(right.min, root->data));
        ret.max = std::max(right.max, std::max(left.max, root->data));
        ret.isBST = true;
        return ret;
    }
    
    ret.isBST = false;
    return ret;
}

int main() {
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(60);
    root->left->left = new Node(5);
    root->left->right = new Node(20);
    root->right->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);
    
    List result = largestBST(root);
    std::cout << "Largest BST subtree size: " << result.size << std::endl;
    
    return 0;
}
