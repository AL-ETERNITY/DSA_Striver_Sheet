// function to solve the problem of boundary traversal of a binary tree
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;    
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

class Solution {
  private:
    bool isLeaf(Node* temp){
        if(temp -> right == NULL && temp -> left == NULL) return true;
        else return false;
    }
    
    void addLeftBoundary(Node* root, vector<int>& ans){
        Node* curr = root -> left;
        while(curr){
            if(!isLeaf(curr)) ans.push_back(curr -> data);
            if(curr -> left) curr = curr -> left;
            else curr = curr -> right;
        }
    }
    
    void addLeaves(Node* root, vector<int>& ans){
        if(isLeaf(root)) {
            ans.push_back(root -> data);
            return;
        }
        
        if(root -> left) addLeaves(root -> left, ans);
        if(root -> right) addLeaves(root -> right, ans);
    }
    
    void addRightBoundary(Node* root, vector<int>& ans){
        Node* curr = root -> right;
        vector<int> temp;
        while(curr){
            if(!isLeaf(curr)) temp.push_back(curr -> data);
            if(curr -> right) curr = curr -> right;
            else curr = curr -> left;
        }
        for(int i = temp.size() - 1; i>=0; i--){
            ans.push_back(temp[i]);
        }
    }
  public:
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        if (!root) return ans;
    
        if (!isLeaf(root)) ans.push_back(root->data);
        addLeftBoundary(root, ans);
        addLeaves(root, ans);
        addRightBoundary(root, ans);
    
        return ans;
    }
};