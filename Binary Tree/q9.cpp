// function to solve the problem of iterative inorder traversal of a binary tree
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
    void inorder(TreeNode* root, vector<int>& ans){
        if(root == NULL){
            return;
        }

        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // vector<int> ans;
        // inorder(root, ans);
        // return ans;

        // Iterative
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while(true) {
            if(curr != NULL) {
                st.push(curr);
                curr = curr -> left;
            } else {
                if(st.empty()) break;
                curr = st.top();
                st.pop();
                ans.push_back(curr -> val);
                curr = curr -> right;
            }
        }

        return ans;
    }
};