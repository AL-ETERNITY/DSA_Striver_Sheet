// function to solve the problem of preorder traversal of a binary tree
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
    void preorder(TreeNode* root, vector<int>& ans){
        if(root == NULL){
            return;
        }

        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // vector<int> ans;
        // preorder(root, ans);
        // return ans;

        vector<int> ans;
        if(!root) return ans;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode* top = st.top();
            st.pop();
            ans.push_back(top -> val);
            if(top -> right) st.push(top -> right);
            if(top -> left) st.push(top -> left);
        }
        return ans;
    }
};