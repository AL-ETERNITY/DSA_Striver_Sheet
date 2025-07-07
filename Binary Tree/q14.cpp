// function to solve the problem of checking if a binary tree is balanced
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
    pair<int, bool> help (TreeNode* root) {
        if(root == NULL) {
            pair<int, bool> p = make_pair (0, true);
            // First - Height.
            // Second - If Balanced
            return p;
        }
        
        pair<int, bool> ans;
        pair<int, bool> left = help(root -> left);
        pair<int, bool> right = help(root -> right);
        ans.first = max(left.first, right.first) + 1;
        ans.second = (abs(left.first - right.first) <= 1);
        if(left.second == false || right.second == false) ans.second = false;
        return ans;
    }
public:
    bool isBalanced(TreeNode* root) {
        return help(root).second;
    }
};