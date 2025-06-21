#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to find the length of a loop in the linked list.
class Solution {
  public:
    int countNodesinLoop(Node *head) {
        Node* fast = head;
        Node* slow = head;
        bool cycle = false;

        while(fast != NULL && fast -> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;

            if(fast == slow) {
                cycle = true;
                break;
            }
        }
        
        if(!cycle) return NULL;

        slow = head;
        while(slow != fast) {
            slow = slow -> next;
            fast = fast -> next;
        }
        
        Node* curr = slow;
        int cnt = 1;
        curr = slow->next;
        while(curr != slow){
            cnt++;
            curr = curr->next;
        }
        
        return cnt;
    }
};