// function to solve the problem of reversing a singly linked list
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        if(head -> next == NULL) return head;

        ListNode* prev = head;
        ListNode* curr = head -> next;
        prev -> next = NULL;

        while(curr != NULL) {
            ListNode* temp  = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};