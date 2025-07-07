// function to solve the problem of level order traversal in a binary tree
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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(!root) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        vector<int> level;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if(temp == NULL){
                ans.push_back(level);
                level.clear();

                if(!q.empty()){
                    q.push(NULL);
                }
            }

            else{
                level.push_back(temp -> val);
                if(temp -> left){
                    q.push(temp->left);
                }
                if(temp -> right){
                    q.push(temp -> right);
                }
            }
        }
        return ans;
    }
};