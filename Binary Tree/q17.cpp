// function to solve the problem of checking if two binary trees are the same
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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // Base Case
        if(p == NULL && q == NULL) return true;
        if(p == NULL && q != NULL) return false;
        if(p != NULL && q == NULL) return false;

        if(isSameTree (p -> left, q -> left) && isSameTree(p -> right, q -> right) && p -> val == q -> val) return true;
        return false;
    }
};