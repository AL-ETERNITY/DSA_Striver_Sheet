// function to solve the problem of top view of binary tree
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(NULL), right(NULL) {}
};

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if (root == NULL) return ans;
        queue<pair<Node *, int>> q;
        map <int, int> mp;
    
        q.push({root,0});
        while(!q.empty()) {
            Node * frontNode = q.front().first;
            int vd = q.front().second;
    
            q.pop();
    
            if(mp.find(vd) == mp.end()) mp[vd] = frontNode -> data;
    
            if(frontNode -> left) q.push(make_pair(frontNode -> left, vd - 1));
            if(frontNode -> right) q.push(make_pair(frontNode -> right, vd + 1));
        }
    
        for(auto i : mp) {
            ans.push_back(i.second);
        }
        return ans;
    }

};