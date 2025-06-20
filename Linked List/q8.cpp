// Function to delete a node at given position.
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Solution {
  public:
    Node* deleteNode(Node* head, int x) {
        if (head == NULL) return NULL;
        
        int cnt = 1;
        Node* curr = head;

        // Traverse to the x-th node (1-based)
        while (cnt < x && curr != NULL) {
            curr = curr->next;
            cnt++;
        }

        // If position x is invalid
        if (curr == NULL) return head;

        // Case 1: Node has both prev and next
        if (curr->prev != NULL && curr->next != NULL) {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }
        // Case 2: Deleting the head node
        else if (curr->prev == NULL) {
            head = curr->next;
            if (head != NULL) head->prev = NULL;
        }
        // Case 3: Deleting the tail node
        else if (curr->next == NULL) {
            curr->prev->next = NULL;
        }

        delete curr;
        return head;
    }
};