/*
Print nodes level by level in Spiral Order
----------------------------------------------------------------
Time: O(n)
*/
#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void printSpiral(Node* root) {
    if (root == nullptr) {
        return;
    }

    stack<Node*> s1;
    stack<Node*> s2;

    s1.push(root);

    while (!s1.empty() || !s2.empty()) {
        while (!s1.empty()) {
            Node* n1 = s1.top();
            s1.pop();

            cout << n1->data << " ";

            if (n1->right != nullptr) {
                s2.push(n1->right);
            }

            if (n1->left != nullptr) {
                s2.push(n1->left);
            }
        }

        while (!s2.empty()) {
            Node* n2 = s2.top();
            s2.pop();

            cout << n2->data << " ";

            if (n2->left != nullptr) {
                s1.push(n2->left);
            }

            if (n2->right != nullptr) {
                s1.push(n2->right);
            }
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

    cout << "Spiral order traversal: ";
    printSpiral(root);

    return 0;
}
