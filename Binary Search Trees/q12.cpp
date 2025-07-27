// function to find predecessor and successor in a Binary Search Tree
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* temp = root;
        Node* succ = NULL;
        Node* pred = NULL;
        
        while(temp) {
            if(temp -> data <= key) {
                temp = temp -> right;
            } else {
                succ = temp;
                temp = temp -> left;
            }
        }
        
        temp = root;
        while(temp) {
            if(temp -> data >= key) {
                temp = temp -> left;
            } else {
                pred = temp;
                temp = temp -> right;
            }
        }
        
        return {pred, succ};
    }
};