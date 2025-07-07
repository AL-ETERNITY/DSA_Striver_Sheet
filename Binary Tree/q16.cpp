// function to solve the problem of finding the maximum path sum in a binary tree
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
    int height(TreeNode* root, int& pathSum){
        if(root == NULL){
            return 0;
        }

        int lh = max(0, height(root -> left, pathSum));
        int rh = max(0, height(root -> right, pathSum));
        pathSum = max(pathSum, root -> val + lh + rh);
        return root -> val + max(lh, rh);
    }
public:
    int maxPathSum(TreeNode* root) {
        int pathSum = INT_MIN;
        height(root, pathSum);
        return pathSum;
    }
};