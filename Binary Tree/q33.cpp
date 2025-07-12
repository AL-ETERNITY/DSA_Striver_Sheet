// function to solve the problem of constructing a binary tree from inorder and postorder traversals
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
    TreeNode* buildTree(vector<int>& inorder, int inStart, int inEnd,
                        vector<int>& postorder, int postStart, int postEnd,
                        map<int,int>& mp) {
        if (postStart > postEnd || inStart > inEnd) return NULL;

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = mp[root->val];
        int numsLeft = inRoot - inStart;

        root->left = buildTree(inorder, inStart, inRoot - 1,
                               postorder, postStart, postStart + numsLeft - 1, mp);

        root->right = buildTree(inorder, inRoot + 1, inEnd,
                                postorder, postStart + numsLeft, postEnd - 1, mp);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }

        return buildTree(inorder, 0, inorder.size() - 1,
                         postorder, 0, postorder.size() - 1, mp);
    }
};