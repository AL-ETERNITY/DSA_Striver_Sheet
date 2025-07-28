// function to find the size of the largest BST subtree in a binary tree
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};
class info {
  public :
        int size;
        int maxi;
        int mini;
        bool isBST;
};

class Solution {
  private:
    info solve(Node * root, int &ans) {
        if(root == NULL) return {0, INT_MIN, INT_MAX, true};
    
        info left = solve(root -> left, ans);
        info right = solve(root -> right, ans);
    
        info current;
        current.size = left.size + right.size + 1;
        current.maxi = max(root -> data, right.maxi);
        current.mini = min(root -> data, left.mini);
        current.isBST = (left.isBST && right.isBST && root -> data < right.mini && root -> data > left.maxi);
    
        if(current.isBST) ans = max(ans, current.size);
        return current;
    }
  public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};