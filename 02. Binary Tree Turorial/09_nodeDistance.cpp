/*
Print all the nodes at k distance from any random node in tree
----------------------------------------------------------------
Time: O(n)
Space: P(n)
*/

//github.com/ddhuu
#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void findNode_Down(TreeNode* node, int k) {
    if (node == nullptr || k < 0)
        return;

    if (k == 0) {
        std::cout << node->val << " ";
        return;
    }

    findNode_Down(node->left, k - 1);
    findNode_Down(node->right, k - 1);
}

int printNode(TreeNode* node, TreeNode* target, int k) {
    if (node == nullptr)
        return -1;

    if (node == target) {
        findNode_Down(node, k);
        return 1;
    }

    int dLeft = printNode(node->left, target, k);
    if (dLeft != -1) {
        if (dLeft == k)
            std::cout << node->val << " ";
        else
            findNode_Down(node->right, k - dLeft - 1);
        return 1 + dLeft;
    }

    int dRight = printNode(node->right, target, k);
    if (dRight != -1) {
        if (dRight == k)
            std::cout << node->val << " ";
        else
            findNode_Down(node->left, k - dRight - 1);
        return 1 + dRight;
    }

    return -1;
}

int main() {
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(8);
    root->right = new TreeNode(22);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(12);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(14);

    TreeNode* target = root->left->right;

    int k = 2;
    printNode(root, target, k);

    
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
