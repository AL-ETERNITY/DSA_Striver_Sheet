// function to solve the problem of flattening a linked list where each node has a next pointer and a bottom pointer.
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *next;
    Node *bottom;
    Node(int x) : data(x), next(nullptr), bottom(nullptr) {}
};
class Solution {
  private:
     Node* merge (Node*& first, Node*& second) {
        Node* dummyNode = new Node(-1);
        Node* temp = dummyNode;

        while(first && second) {
            if(first -> data < second -> data) {
                temp -> bottom = first;
                first = first -> bottom;
            } else {
                temp -> bottom = second;
                second = second -> bottom;
            }
            temp -> next = nullptr;
            temp = temp -> bottom;
        }
        if(first) {
            temp -> bottom = first;
        } else {
            temp -> bottom = second;
        }
        Node* toReturn = dummyNode -> bottom;
        delete dummyNode;
        return toReturn;
    }
  public:
    Node *flatten(Node *root) {
        // Base case
        if (!root || !root->next) return root;

        // Recursively flatten the next list
        Node* mergedHead = flatten(root->next);

        // Merge this list with the next flattened list
        root = merge(root, mergedHead);

        return root;
    }
};