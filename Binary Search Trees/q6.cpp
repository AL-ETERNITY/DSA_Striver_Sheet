// function to insert a value into a Binary Search Tree (BST)
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            TreeNode* temp = new TreeNode(val);
            return temp;
        }

        if(root -> val >= val){
            root -> left = insertIntoBST(root->left, val);
        }
        else{
            root -> right = insertIntoBST(root->right, val);
        }

        return root;
    }
};