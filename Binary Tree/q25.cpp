// function to find the lowest common ancestor of two nodes in a binary tree
#include <iostream>
using namespace std;
            
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) {
            return NULL;
        }
        
        if(root  == p || root == q ) return root;
        
        TreeNode* leftAns = lowestCommonAncestor(root -> left, p, q);
        TreeNode* rightAns = lowestCommonAncestor(root -> right, p, q);
        
        if(leftAns != NULL && rightAns != NULL) {
            return root;
        }
        else if(leftAns != NULL && rightAns == NULL) {
            return leftAns;
        }
        else if(leftAns == NULL && rightAns != NULL) {
            return rightAns;
        }
        else {
            return NULL;
        }
    }
};