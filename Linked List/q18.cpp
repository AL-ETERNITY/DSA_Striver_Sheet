// function to solve the problem of removing the nth node from the end of a linked list
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast n+1 steps ahead
        for(int i = 0; i <= n; ++i){
            fast = fast->next;
        }

        // Move both fast and slow
        while(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        // Delete the nth node
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};
