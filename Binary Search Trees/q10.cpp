// function to find the lowest common ancestor of two nodes in a Binary Search Tree
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root != NULL) {
            if(root -> val > p -> val && root -> val > q -> val) root = root -> left;
            else if(root -> val < p -> val && root -> val < q -> val) root = root -> right;

            else return root;
        }

        return root;
    }
};