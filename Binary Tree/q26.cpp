// function to solve the problem of finding the maximum width of a binary tree
#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        
        int max_width = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int level_size = q.size();
            int mini = q.front().second;
            int first, last;            
            for (int i = 0; i < level_size; ++i) {
                auto node_index_pair = q.front();
                TreeNode* node = node_index_pair.first;
                int node_index = node_index_pair.second - mini;  // To prevent overflow
                q.pop();
                
                if(i == 0) first = node_index;
                if(i == level_size - 1) last = node_index;
                
                if (node->left) {
                    q.push({node->left, 2LL * node_index + 1});
                }
                
                if (node->right) {
                    q.push({node->right, 2LL * node_index + 2});
                }
            }
            max_width = max(max_width, last - first + 1);
        }
        
        return max_width;
    }
};