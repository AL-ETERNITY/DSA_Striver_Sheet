// function to delete all occurrences of a given value x from a doubly linked list
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
    void deleteAllOccurOfX(Node** head_ref, int x) {
        Node* curr = *head_ref;
        
        while (curr) {
            Node* temp = curr->next;
            
            if (curr->data == x) {
                // Case 1: Both prev and next exist (middle node)
                if (curr->prev && curr->next) {
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                }
                // Case 2: Head node
                else if (curr->prev == NULL) {
                    *head_ref = curr->next;
                    if (*head_ref != NULL)
                        (*head_ref)->prev = NULL;
                }
                // Case 3: Tail node
                else if (curr->next == NULL) {
                    curr->prev->next = NULL;
                }

                delete curr;
            }

            curr = temp;
        }
    }
};