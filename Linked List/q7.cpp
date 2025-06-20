// Function to insert a new node at given position in doubly linked list.
#include <bits/stdc++.h>
using namespace std;
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; 
class Solution {
  public:
    Node* addNode(Node* head, int pos, int data) {
        int cnt = 0;
        Node* curr = head;

        while(cnt != pos && curr != NULL) {
            curr = curr->next;
            cnt++;
        }

        Node* newNode = new Node(data);
        
        newNode->next = curr->next;
        newNode->prev = curr;
        
        if(curr->next != NULL) {
            curr->next->prev = newNode;
        }

        curr->next = newNode;
        
        return head;
    }
};