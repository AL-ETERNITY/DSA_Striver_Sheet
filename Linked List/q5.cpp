// function to solve the problem of searching for a key in a linked list
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

class Solution {
  public:
    bool searchKey(int n, Node* head, int key) {
        Node* curr = head;
        while(curr != NULL){
            if(key == curr->data) return true;
            else curr = curr->next;
        }
        return false;
    }
};