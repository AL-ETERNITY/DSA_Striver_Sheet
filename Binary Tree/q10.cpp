// function to solve the problem of postorder traversal of a binary tree
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
    void postorder(TreeNode* root, vector<int>& ans){
        if(root == NULL){
            return;
        }

        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        // vector<int> ans;
        // postorder(root, ans);
        // return ans;

        // iterative approach using 2 stack
        // vector<int> ans;
        // if(!root) return ans;
        // stack<TreeNode*> st1, st2;
        // st1.push(root);

        // while(!st1.empty()) {
        //     TreeNode* top = st1.top();
        //     st1.pop();
        //     st2.push(top);
        //     if(top -> left) st1.push(top -> left);
        //     if(top -> right) st1.push(top -> right);
        // }

        // while(!st2.empty()) {
        //     ans.push_back(st2.top() -> val);
        //     st2.pop();
        // }

        // return ans;

        // iterative approach using one stack
        TreeNode* curr = root;
        stack<TreeNode*> st;
        vector<int> ans;
        while(curr != NULL || !st.empty()) {
            if(curr != NULL) {
                st.push(curr);
                curr = curr -> left;
            } else {
                TreeNode* temp = st.top() -> right;
                if (temp != NULL) curr = temp;
                else {
                    TreeNode* temp = st.top();
                    st.pop();
                    ans.push_back(temp -> val);

                    while(!st.empty() && temp == st.top() -> right) {
                        temp = st.top(); st.pop();
                        ans.push_back(temp -> val);
                    }
                }
            }
        }
        return ans;
    }
};