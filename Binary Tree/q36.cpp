// function to solve preorder traversal of a binary tree using morris traversal
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
    TreeNode* find(TreeNode* root) {
        TreeNode* pred = root->left;
        while (pred->right != NULL && pred->right != root) {
            pred = pred->right;
        }
        return pred;
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> ans;
        while (curr != NULL) {
            if (curr->left == NULL) {
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* pred = find(curr);
                if (pred->right == NULL) {
                    pred->right = curr;
                    ans.push_back(curr->val); 
                    curr = curr->left;
                } else {
                    pred->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};
