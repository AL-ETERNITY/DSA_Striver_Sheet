// function to solve the problem of getting all three traversals in a single iteration of a binary tree
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(NULL), right(NULL) {}
};

vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Iterative in single traversal

    vector<vector<int>> ans;

    if(!root) return ans;

    vector<int> inorder;
    vector<int> preorder;
    vector<int> postorder;

    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});

    // 1 - Preorder
    // 2 - Inorder
    // 3 - Postorder
    while(!st.empty()) {
        pair<TreeNode*, int> top = st.top(); st.pop();
        TreeNode* topNode = top.first;
        int num = top.second;

        switch (num) {
            case 1:
                preorder.push_back(topNode -> data);
                st.push({topNode, num + 1});

                if(topNode -> left) st.push({topNode -> left, 1});
                break;
            case 2:
                inorder.push_back(topNode -> data);
                st.push({topNode, num + 1});

                if(topNode -> right) st.push({topNode -> right, 1});
                break;
            case 3:
                postorder.push_back(topNode -> data);
                break;
        }

    }

    ans.push_back(inorder);
    ans.push_back(preorder);
    ans.push_back(postorder);

    return ans;
}