// function to insert a node at the end of a linked list
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; 

class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        Node* newNode = new Node(x);
        Node* tail = NULL;
        if(head == NULL){
            head = tail = newNode;
        }
        else{
            tail = head;
            while(tail->next){
                tail = tail->next;
            }
            tail->next = newNode;
            tail = newNode;
        }
        return head;
    }
};