// function to recover a binary search tree where two nodes are swapped
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
    void recoverTree(TreeNode* root) {
        TreeNode* curr = root;
        TreeNode* prev = NULL;
        TreeNode* first = NULL;
        TreeNode* second = NULL;

        while(curr != NULL){
            if(curr -> left == NULL){
                if(prev && prev -> val > curr -> val){
                    if(first == NULL){
                        first = prev;
                    }
                    second = curr;
                }
                prev = curr;
                curr = curr -> right;
            }
            else{
                TreeNode* temp = curr -> left;
                while(temp -> right != NULL && temp -> right != curr){
                    temp = temp -> right;
                }
                if (temp->right == NULL) {
                    // Make thread
                    temp->right = curr;
                    curr = curr->left;
                } 
                else {
                    // Remove thread
                    temp->right = NULL;

                    // Visit node
                    if (prev && prev->val > curr->val) {
                        if (first == NULL){
                            first = prev;
                        }
                        second = curr;
                    }
                    prev = curr;
                    curr = curr->right;
                }
            }
        }

        if (first && second) {
            int temp = first->val;
            first->val = second->val;
            second->val = temp;
        }
    }
};