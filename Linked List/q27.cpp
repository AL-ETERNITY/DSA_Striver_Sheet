// function to solve the problem of removing duplicates from a doubly linked list
#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
    Node(int x) { data = x; next = prev = NULL; }
};
class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        if(!head) return NULL;
        if(!head->next) return head;

        Node* curr = head->next;
        while(curr){
            Node* temp = curr->next;
            if(curr->data == curr->prev->data){
                // Case 1: Both prev and next exist (middle node)
                if (curr->prev && curr->next) {
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                }
                // Case 3: Tail node
                else if (curr->next == NULL) {
                    curr->prev->next = NULL;
                }
                
                delete curr;
            }
            curr = temp;
        }
        return head;
    }
};