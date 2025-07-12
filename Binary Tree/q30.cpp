// function to count the number of nodes in a complete binary tree
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int leftHeight(TreeNode* root) {
        int height = 0;
        while(root) {
            root = root -> left;
            height++;
        }
        return height;
    }

    int rightHeight(TreeNode* root) {
        int height = 0;
        while(root) {
            root = root -> right;
            height++;
        }
        return height;
    }

    int countNodes(TreeNode* root) {

        if(root == NULL) return 0;

        int lh = leftHeight(root);
        int rh = rightHeight(root);

        if(lh == rh) return (1 << lh) - 1;
        return countNodes(root -> left) + countNodes(root -> right) + 1;
    }
};