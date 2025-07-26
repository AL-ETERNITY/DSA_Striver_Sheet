// function to solve the problem of searching a value in a Binary Search Tree (BST) using iterative approach
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* temp = root;
        while(temp != NULL){
            if(temp->val == val){
                return temp;
            }
            else if(temp->val > val){
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }
        }
        return NULL;
    }
};