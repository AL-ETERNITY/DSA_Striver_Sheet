// function to solve the problem of checking if a binary tree is symmetric
#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
private:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // Base Case
        if(p == NULL && q == NULL) return true;
        if(p == NULL || q == NULL) return false;

        // Mirror check: left vs right and right vs left
        if(isSameTree(p->left, q->right) && 
           isSameTree(p->right, q->left) && 
           p->val == q->val) return true;

        return false;
    }

public:
    bool isSymmetric(TreeNode* root) {
        // An empty tree is symmetric
        if(root == NULL) return true;

        // Directly call isSameTree on left and right subtrees
        return isSameTree(root->left, root->right);
    }
};
