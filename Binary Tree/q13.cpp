// function to solve the problem of finding the maximum depth of a binary tree
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
    int levelorder(TreeNode* root){
        int cnt = 0;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if(temp == NULL){
                cnt++;
                if(!q.empty()){
                    q.push(NULL);
                }
            }

            else{
                if(temp -> left){
                    q.push(temp -> left);
                }
                if(temp -> right){
                    q.push(temp -> right);
                }
            }
        }

        return cnt;
    }
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0; 
        return levelorder(root);
    }
};