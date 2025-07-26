// function to solve the problem of finding the minimum value in a Binary Search Tree (BST)
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
class Solution {
  public:
    int minValue(Node* root) {
        Node* temp = root;
        while(temp -> left != NULL){
            temp = temp -> left;
        }
        return temp->data;
    }
};