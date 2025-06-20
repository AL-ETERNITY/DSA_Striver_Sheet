#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// function to solve the problem of reversing a singly linked list using recursion
class Solution {
private:
    ListNode* rev(ListNode* prev, ListNode* curr) {
        if(curr == NULL) return prev;

        ListNode* forward = curr -> next;
        curr -> next = prev;
        return rev(curr, forward);
    }
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        ListNode* curr = head -> next;
        head -> next = NULL;
        return rev(head, curr);
    }
};