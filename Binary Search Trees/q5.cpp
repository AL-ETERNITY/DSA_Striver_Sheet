// function to find the floor value in a Binary Search Tree (BST)
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
    int floor(Node* root, int x) {
        Node* temp = root;
        int ans = -1;
        while(temp != NULL){
            if(temp -> data <= x){
                ans = temp->data;
                temp = temp -> right;
            }
            else{
                temp = temp -> left;
            }
        }
        return ans;
    }
};