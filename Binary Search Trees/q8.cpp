// function to find the k-th smallest element in a Binary Search Tree (BST) using inorder traversal
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
    int inorder(TreeNode* root, int k, int &cnt) {
        if(root == NULL) return -1;

        // L
        int left = inorder(root -> left, k, cnt);

        if(left != -1) return left;

        // N
        cnt++;
        if(cnt == k) return root -> val;

        // R
        return inorder(root -> right, k, cnt);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        return inorder(root, k, cnt);
    }
};

// if we are asked to find the k-th largest element, we can simply find the total number of nodes in the BST and then find the (total - k + 1)-th smallest element using the same approach as above.