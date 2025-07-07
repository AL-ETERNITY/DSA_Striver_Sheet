// function to solve the problem of tree traversal in a binary tree
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

void inorder(TreeNode* root, vector<int>& output1){
    if(root == NULL){
        return;
    }
    inorder(root->left, output1);
    output1.push_back(root->data);
    inorder(root->right, output1);
}

void preorder(TreeNode* root, vector<int>& output2){
    if(root == NULL){
        return;
    }
    output2.push_back(root->data);
    preorder(root->left, output2);
    preorder(root->right, output2);
}

void postorder(TreeNode* root, vector<int>& output3){
    if(root == NULL){
        return;
    }
    postorder(root->left, output3);
    postorder(root->right, output3);
    output3.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(TreeNode *root){
    vector<vector<int>> ans;

    vector<int> output1;
    inorder(root, output1);
    ans.push_back(output1);

    vector<int> output2;
    preorder(root, output2);
    ans.push_back(output2);

    vector<int> output3;
    postorder(root, output3);
    ans.push_back(output3);

    return ans;
}
