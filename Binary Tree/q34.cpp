// function to solve the problem of serializing and deserializing a binary tree
#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";

        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* top = q.front();
            q.pop();
            if(top == NULL) s += "#,";
            else {
                s += to_string(top -> val) + ',';
            }

            if(top != NULL) {
                q.push(top -> left);
                q.push(top -> right);
            }
        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "") return NULL;

        stringstream s(data);
        string str;

        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            getline(s, str, ',');
            if(str == "#") {
                node -> left = NULL;
            } 
            else {
                node -> left = new TreeNode(stoi(str));
                q.push(node -> left);
            }

            getline(s, str, ',');
            if(str == "#") {
                node -> right = NULL;
            } 
            else {
                node -> right = new TreeNode(stoi(str));
                q.push(node -> right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));