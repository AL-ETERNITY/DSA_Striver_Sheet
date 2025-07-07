// function to create a binary tree from a vector of integers
#include <bits/stdc++.h>
using namespace std;
class node {
    public:
        int data;
        node* left;
        node* right;

    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};
class Solution {
  public:

    void create_tree(node* root0, vector<int>& vec) {
        queue<node*> q;
        q.push(root0);
        
        int i = 0;
        while(!q.empty()){
            node* temp = q.front();
            q.pop();
            
            if((2*i + 1) < 7){
                temp -> left = new node(vec[2*i + 1]);
                q.push(temp -> left);
            }
            
            if((2*i + 2) < 7){
                temp -> right = new node(vec[2*i + 2]);
                q.push(temp -> right);
            }
            i++;
        }
    }
};