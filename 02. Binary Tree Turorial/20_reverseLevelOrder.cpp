/*
Print binary nodes level by level in reverse order.
*/
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void levelOrderReverseTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    stack<TreeNode*> nodeStack;
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (!nodeQueue.empty()) {
        TreeNode* n1 = nodeQueue.front();
        nodeQueue.pop();
        nodeStack.push(n1);

        if (n1->right != NULL) {
            nodeQueue.push(n1->right);
        }
        if (n1->left != NULL) {
            nodeQueue.push(n1->left);
        }
    }

    while (!nodeStack.empty()) {
        TreeNode* node = nodeStack.top();
        nodeStack.pop();
        cout << node->val << " ";
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Level Order Reverse Traversal: ";
    levelOrderReverseTraversal(root);
    cout << endl;

    return 0;
}
