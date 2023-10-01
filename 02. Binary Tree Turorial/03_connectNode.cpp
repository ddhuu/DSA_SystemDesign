/*
Algorithm to connect all the nodes in the same level
----------------------------------------------------------------
Time: O(n)
Space: O(1)
*/

//github.com/ddhuu
#include <iostream>

class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node* next;

    Node(int val) : data(val), left(nullptr), right(nullptr), next(nullptr) {}
};

void connectNode(Node* root) {
    if (root == nullptr) {
        return;
    }

    if (root->left && root->right) {
        root->left->next = root->right;
        if (root->next) {
            root->right->next = root->next->left ? root->next->left : root->next->right;
        }
    } else if (root->left && root->next) {
        if (root->next->left) {
            root->left->next = root->next->left;
        } else {
            root->left->next = root->next->right;
        }
    } else if (root->right && root->next) {
        if (root->next->left) {
            root->right->next = root->next->left;
        } else {
            root->right->next = root->next->right;
        }
    }

    connectNode(root->right);
    connectNode(root->left);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    connectNode(root);

   
    Node* curr = root;
    while (curr) {
        Node* temp = curr;
        while (temp) {
            if (temp->next) {
                std::cout << temp->data << " -> " << temp->next->data << " ";
            } else {
                std::cout << temp->data << " -> NULL ";
            }
            temp = temp->next;
        }
        std::cout << std::endl;
        curr = curr->left;
    }

    return 0;
}

