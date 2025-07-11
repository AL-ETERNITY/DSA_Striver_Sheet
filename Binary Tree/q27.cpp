// function to solve the problem of checking if all nodes of a binary tree
// have the value equal to the sum of their child nodes

#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;    
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

class Solution {
  private:
    pair<bool, int> isSum (Node* root) {
        // First - is Sum
        // Second - Sum
        if(root == NULL) return {true, 0};
        
        if(root -> left == NULL && root -> right == NULL) return {true, root -> data};
        
        auto left = isSum(root -> left);
        auto right = isSum(root -> right);
        
        return {left.first && right.first && (root -> data == left.second + right.second), root -> data};
    }
  public:
    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.
    int isSumProperty(Node *root) {
        return isSum(root).first;
    }
};