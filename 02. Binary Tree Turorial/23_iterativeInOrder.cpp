#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int value) : val(value), left(nullptr), right(nullptr) {}
};

void inOrder(Node* root) {
    if (root == nullptr) {
        return;
    }

    stack<Node*> nodeStack;
    Node* curr = root;

    while (curr != nullptr || !nodeStack.empty()) {
        while (curr != nullptr) {
            nodeStack.push(curr);
            curr = curr->left;
        }

        curr = nodeStack.top();
        nodeStack.pop();

        cout << curr->val << " ";

        curr = curr->right;
    }
}

int main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    cout << "In-order traversal: ";
    inOrder(root);

    return 0;
}
