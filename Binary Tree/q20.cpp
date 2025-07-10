// function to solve the problem of vertical traversal of a binary tree
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> mp; // col → row → list of values
        vector<vector<int>> ans;
        if (!root) return ans;

        queue<pair<TreeNode*, pair<int, int>>> q; // node, {col, row}
        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto temp = q.front(); q.pop();
            TreeNode* curr = temp.first;
            int col = temp.second.first;
            int row = temp.second.second;

            mp[col][row].push_back(curr->val);

            if (curr->left)  q.push({curr->left, {col - 1, row + 1}});
            if (curr->right) q.push({curr->right, {col + 1, row + 1}});
        }

        for (auto& colPair : mp) {
            vector<int> colValues;
            for (auto& rowPair : colPair.second) {
                vector<int>& nodes = rowPair.second;
                sort(nodes.begin(), nodes.end());
                colValues.insert(colValues.end(), nodes.begin(), nodes.end());
            }
            ans.push_back(colValues);
        }

        return ans;
    }
};
