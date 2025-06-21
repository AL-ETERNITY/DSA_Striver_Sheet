// function to solve the problem of adding one to a linked list representing a number
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
class Solution {
  private:
    Node* reverse(Node* head){
        Node* prev = head;
        Node* curr = head->next;
        prev->next = NULL;
        while(curr){
            Node* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

  public:
    Node* addOne(Node* head) {
        if(head == NULL) return NULL;

        if(head->next == NULL){
            head->data += 1;
            if(head->data == 10){
                head->data = 0;
                Node* newNode = new Node(1);
                newNode->next = head;
                head = newNode;
            }
            return head;
        }

        Node* newHead = reverse(head);
        Node* curr = newHead;
        int carry = 1;
        Node* prev = NULL;

        while(curr && carry){
            int sum = curr->data + carry;
            curr->data = sum % 10;
            carry = sum / 10;
            prev = curr;
            curr = curr->next;
        }

        if(carry){
            Node* newNode = new Node(1);
            prev->next = newNode;
        }

        Node* original_head = reverse(newHead);
        return original_head;
    }
};
