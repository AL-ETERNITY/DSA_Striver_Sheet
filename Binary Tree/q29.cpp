// function to solve the problem of finding the minimum time to burn a binary tree from a target node
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

class Solution {
  private:
    void markParents(Node* root, unordered_map<Node*, Node*>& parents){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            if(curr -> left){
                parents[curr -> left] = curr;
                q.push(curr -> left);
            }
            if(curr -> right){
                parents[curr -> right] = curr;
                q.push(curr -> right);
            }
        }
    }
  public:
    int minTime(Node* root, int target) {
        unordered_map<Node*, Node*> parents;
        markParents(root, parents);
        
        unordered_map<Node*, bool> vis;
    
        // Find the target node from the tree (you cannot use target as int directly)
        Node* start = NULL;
        queue<Node*> find;
        find.push(root);
        while (!find.empty()) {
            Node* node = find.front(); find.pop();
            if (node->data == target) {
                start = node;
                break;
            }
            if (node->left) find.push(node->left);
            if (node->right) find.push(node->right);
        }
    
        queue<Node*> q;
        q.push(start);
        vis[start] = true;
        
        int time = 0;
        while(!q.empty()) {
            int size = q.size();
            bool burned = false;
    
            for(int i = 0; i < size; i++) {
                Node* curr = q.front(); q.pop();
        
                if (curr->left && !vis[curr->left]) {
                    vis[curr->left] = true;
                    q.push(curr->left);
                    burned = true;
                }
                if (curr->right && !vis[curr->right]) {
                    vis[curr->right] = true;
                    q.push(curr->right);
                    burned = true;
                }
                if (parents[curr] && !vis[parents[curr]]) {
                    vis[parents[curr]] = true;
                    q.push(parents[curr]);
                    burned = true;
                }
            }
    
            if (burned) time++;
        }
    
        return time;
    }

};