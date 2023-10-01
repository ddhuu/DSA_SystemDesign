/*
We have the inorder and postorder traversal sequence of a binary tree to generate 
the Binary tree.
*/
#include <iostream>


struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    Node* buildTree(int inOrder[], int postOrder[], int start, int end, int& current) {
        if (start > end) {
            return nullptr;
        }
        
        current--;
        Node* node = new Node(postOrder[current]);
        
        if (start == end) {
            return node;
        }
        
        int index = search_inOrder(inOrder, postOrder[current], start, end);
        
        node->right = buildTree(inOrder, postOrder, index + 1, end, current);
        node->left = buildTree(inOrder, postOrder, start, index - 1, current);
        
        return node;
    }
    
    int search_inOrder(int inOrder[], int value, int start, int end) {
        for (int i = start; i <= end; ++i) {
            if (inOrder[i] == value) {
                return i;
            }
        }
        return -1; // Value not found (should not happen if valid inputs are provided)
    }
    void inOrder(Node* node) {
    if (node == nullptr) {
        return;
    }
    inOrder(node->left);
    std::cout << node->data << " ";
    inOrder(node->right);
}
};

int main() {
    Solution solution;

    int inOrder[] = {9, 3, 15, 20, 7};
    int postOrder[] = {9, 15, 7, 20, 3};
    int size = sizeof(inOrder) / sizeof(inOrder[0]);
    int current = size;

    Node* root = solution.buildTree(inOrder, postOrder, 0, size - 1, current);
    solution.inOrder(root);
    

    return 0;
}
