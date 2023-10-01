/*
Print all the nodes that are  distance k from a leaf. If k is more than the height of the Tree,
then nothing should be printed.
----------------------------------------------------------------
Time: O(n)
*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void leafDistance(Node* node, int k, int arr[], bool visited[], int count) {
    if (node == nullptr)
        return;

    arr[count] = node->data;
    visited[count] = false;

    if (node->left == nullptr && node->right == nullptr && count - k >= 0 && !visited[count - k]) {
        cout << arr[count - k] << endl;
        visited[count - k] = true;
        return;
    }

    leafDistance(node->left, k, arr, visited, count + 1);
    leafDistance(node->right, k, arr, visited, count + 1);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int k = 2;
    int arr[100]; // Adjust the size as needed
    bool visited[100] = { false }; // Initialize visited array

    leafDistance(root, k, arr, visited, 0);

   
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
