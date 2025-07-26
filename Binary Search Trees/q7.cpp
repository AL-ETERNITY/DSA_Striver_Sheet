// fucntion to delete a node from a Binary Search Tree (BST)
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
    TreeNode* minVal(TreeNode* root){
        TreeNode* temp = root;
        while(temp->left != NULL){
            temp = temp->left;
        }
        return temp;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;

        if(root -> val > key){
            root -> left = deleteNode(root -> left, key);
            return root;
        }
        else if(root -> val < key){
            root -> right = deleteNode(root -> right, key);
            return root;
        }
        else{
            if(root -> left == NULL && root -> right == NULL){
                delete root;
                return NULL;
            }
            else if(root -> left != NULL && root -> right == NULL){
                TreeNode* temp = root -> left;
                delete root;
                return temp;
            }
            else if(root -> left == NULL && root -> right != NULL){
                TreeNode* temp = root -> right;
                delete root;
                return temp;
            }
            else{
                int mini = minVal(root -> right) -> val;
                root -> val = mini;
                root -> right = deleteNode(root -> right, mini);
            }
        }
        return root;
    }
};