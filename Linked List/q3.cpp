// function to delete a node in a singly linked list
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* curr = node;
        while(curr -> next != NULL) {
            curr -> val = curr -> next -> val;
            if(curr -> next -> next == NULL) curr -> next = NULL;
            else curr = curr -> next;
        }
    }
};