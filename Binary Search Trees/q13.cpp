// function to solve the problem of binary search tree iterator
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Definition for a binary tree node used in Solution class.
struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

class BSTIterator {
private:
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        TreeNode* temp = root;
        while(temp) {
            st.push(temp);
            temp = temp -> left;
        }
    }
    
    int next() {
        TreeNode* top = st.top(); st.pop();
        int toReturn = top -> val;
        if(top -> right) {
            top = top -> right;
            while(top) {
                st.push(top);
                top = top -> left;
            }
        }

        return toReturn;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

// function to merge two Binary Search Trees (BSTs)
class Solution {
  private:
    void inorder(Node* root, vector<int> &ino) {
        if(root == NULL) return;
        
        inorder(root -> left, ino);
        ino.push_back(root -> data);
        inorder(root -> right, ino);
    }
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2) {
        vector<int> ans;
        
        inorder(root1, ans);
        inorder(root2, ans);
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};