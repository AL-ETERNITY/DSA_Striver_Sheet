// function to solve the problem of finding the ceil value in a Binary Search Tree (BST)
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

int findCeil(Node* root, int input) {
    Node* temp = root;
    int ans = -1;
    while(temp != NULL){
        if(temp -> data >= input){
            ans = temp->data;
            temp = temp -> left;
        }
        else{
            temp = temp -> right;
        }
    }
    return ans;
}