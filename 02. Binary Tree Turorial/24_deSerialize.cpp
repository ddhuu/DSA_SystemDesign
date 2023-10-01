/*
----------------------------------------------------------------\
Time: O(n)
Space: O(1)
*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int index = -1;
    
    void Serialize(Node* node, int preOrder[], int& index) {
        if (node == nullptr) {
            preOrder[index++] = -1;
            return;
        }
        preOrder[index++] = node->data;
        Serialize(node->left, preOrder, index);
        Serialize(node->right, preOrder, index);
    }

    Node* deSerialize(int preOrder[], int& index) {
        index++;
        if (preOrder[index] == -1) {
            return nullptr;
        }
        Node* node = new Node(preOrder[index]);
        node->left = deSerialize(preOrder, index);
        node->right = deSerialize(preOrder, index);
        return node;
    }
    void inOrder(Node* node){
        if (node == nullptr) {
            return;
        }
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    };
};

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    Solution solution;
    int *preOrder = new int[100]; // Make sure the array size is large enough
    int index = -1;

    solution.Serialize(root, preOrder, index);

    cout << "Serialized Array: ";
    for (int i = 0; i < index; i++) {
        cout << preOrder[i] << " ";
    }
    cout << endl;

    index = -1;
    Node* newRoot = solution.deSerialize(preOrder, index);

    cout << "DeSerialized Tree (InOrder Traversal): ";
    // Perform InOrder traversal to check if tree is correctly deserialized
    
    solution.inOrder(newRoot);
    cout << endl;

    return 0;
}
