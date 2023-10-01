/*
Linked list is given, in addition to the next reference, each node has a child pointer
that can point to a separate  list. With head node, flatten the list to a single level
linked list.
----------------------------------------------------------------
Time: O(n)
*/





#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* child;

    Node(int x) : data(x), next(nullptr), child(nullptr) {}
};

class Solution {
public:
    Node* mergeLists(Node* left, Node* right, Node*& temp) {
        if (left == nullptr) return right;
        if (right == nullptr) return left;

        temp = right;
        right = right->next;

        temp->next = left;
        temp->next->child = nullptr;

        temp->child = mergeLists(temp->child, right, temp);

        return temp;
    }

    Node* flattenLinkedList(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        Node* temp = nullptr;

        node->next = flattenLinkedList(node->next);
        node = mergeLists(node, node->next, temp);

        return node;
    }
};

int main() {
    Node* root = new Node(1);
    root->next = new Node(2);
    root->next->next = new Node(3);
    root->next->child = new Node(7);
    root->next->child->next = new Node(8);
    root->next->child->next->next = new Node(9);
    root->next->child->child = new Node(10);
    root->next->child->child->next = new Node(11);

    Solution solution;
    Node* flattened = solution.flattenLinkedList(root);

    // Print the flattened linked list
    Node* current = flattened;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->child;
    }
    std::cout << std::endl;

 

    return 0;
}
