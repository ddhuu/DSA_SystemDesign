#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void preOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    
    stack<Node*> nodeStack;
    nodeStack.push(root);
    
    while (!nodeStack.empty()) {
        Node* myNode = nodeStack.top();
        nodeStack.pop();
        
        cout << myNode->data << " ";
        
        if (myNode->right != nullptr) {
            nodeStack.push(myNode->right);
        }
        
        if (myNode->left != nullptr) {
            nodeStack.push(myNode->left);
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
    
    cout << "Preorder traversal: ";
    preOrder(root);
    
    return 0;
}
