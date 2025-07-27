// function to validate if a binary tree is a Binary Search Tree (BST)
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
private:
    bool validateBSTUtil(TreeNode *node, long long min, long long max) {
        if (node == NULL) return true;

        if (node->val <= min || node->val >= max) return false;

        return validateBSTUtil(node->left, min, node->val) &&
            validateBSTUtil(node->right, node->val, max);
    }
public:
    bool isValidBST(TreeNode* root) {
        return validateBSTUtil(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }
};